/* 신축성 있는 배열 멤버 Flexible Array Members */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
        Flexible array member (struct hack in GCC)
    */

    struct flex
    {
        size_t count;
        double average;
        double values[];  // flexible array member (last member!) : 구조체의 마지막 멤버로 길이가 없는 배열을 선언한다(이 자체로는 메모리를 차지하지 않는다) 
    };

    const size_t n = 3;

    struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double)); // 구조체 크기 뿐만 아니라 내가 배열로 사용하고 싶은 크기만큼 추가로 동적할당을 받음 여기선 double 3개를 받았다. 구조체 맨 뒤에 배열이 있는데 동적할당을 받아서 동적할당 배열처럼 사용할 수 있다.
    if (pf == NULL) exit(1);

    printf("\nFlexible array member\n");
    printf("Sizeof struct flex %zd\n", sizeof(struct flex)); // 값이 16이 나온다. 
    printf("Sizeof *pf %zd\n", sizeof(*pf));
    printf("Sizeof malloc %zd\n", sizeof(struct flex) + n * sizeof(double));

    printf("%lld\n", (long long)pf);
    printf("%lld\n", (long long)&pf->count);
    printf("%zd\n", sizeof(pf->count));
    printf("%lld\n", (long long)&pf->average);
    printf("Address of pf->values %lld\n", (long long)&pf->values);
    printf("Value of pf->values %lld\n", (long long)pf->values);
    printf("Sizeof pf->values %zd\n", sizeof(pf->values));  // VS에서는 경고는 발생하지만 컴파일 가능 사이즈가 0 원래는 size_t가 padding으로 8바이트 average가 8바이트 16바이트가 할당되는데 거기에 추가로 메모리를 더 받아서 values[]로부터 시작되는 배열로서 사용됨

    pf->count = n;        // 동적할당을 받고난 이후에는 할당받은 크기를 다시 알기 힘들기 때문에 이렇게 저장해놓는다
    pf->values[0] = 1.1;
    pf->values[1] = 2.1;
    pf->values[2] = 3.1;

    pf->average = 0.0;
    for (unsigned i = 0; i < pf->count; ++i)
        pf->average += pf->values[i];
    pf->average /= (double)pf->count;

    printf("Average = %f\n", pf->average);

    return 0;
    
    /*
     그렇다면 멤버로 포인터를 추가하고 동적할당하는 것과 어떤 차이가 있나?
    struct nonflex
    {
        size_t count;
        double average;
        double *values;  // 포인터 변수이기에 그 자체로 메모리를 차지하며 동적할당 배열((double*)malloc(sizeof(double) * n);)이 count, average와 연속된 주소를 갖지 않는다. 어디에 위치하는지 알 수 없다. 따라서 구조체가 차지하는 메모리와 마지막 멤버가 가리키는 메모리가 멀리 떨어질 수 있다.
                         // flexible array member는 그 자체로는 메모리를 차지하지 않으며 count, average와 연속된 주소를 갖는다
    };

    struct nonflex nf;
    nf.values = (double*)malloc(sizeof(double) * n);
    */

    /*
        주의 사항
        struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
        if(pf2 == NULL) exit(1);

        *pf2 = *pf;  // Don't copy flexible members(동적할당 받은 건 40이지만 사이즈는 16이다. 컴파일러 입장에서는 대입을 시도했을 때 16바이트만 복사를 해준다. 컴파일러 입장에서는 동적할당을 받았기 때문에 알 수가 없다.), use memcpy() instead
        //memcpy를 사용해서 전체의 메모리를 복사해줄 수 있다.
        free(pf);
        free(pf2);
    */
}