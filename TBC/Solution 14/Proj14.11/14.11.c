/* ���༺ �ִ� �迭 ��� Flexible Array Members */
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
        double values[];  // flexible array member (last member!) : ����ü�� ������ ����� ���̰� ���� �迭�� �����Ѵ�(�� ��ü�δ� �޸𸮸� �������� �ʴ´�) 
    };

    const size_t n = 3;

    struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double)); // ����ü ũ�� �Ӹ� �ƴ϶� ���� �迭�� ����ϰ� ���� ũ�⸸ŭ �߰��� �����Ҵ��� ���� ���⼱ double 3���� �޾Ҵ�. ����ü �� �ڿ� �迭�� �ִµ� �����Ҵ��� �޾Ƽ� �����Ҵ� �迭ó�� ����� �� �ִ�.
    if (pf == NULL) exit(1);

    printf("\nFlexible array member\n");
    printf("Sizeof struct flex %zd\n", sizeof(struct flex)); // ���� 16�� ���´�. 
    printf("Sizeof *pf %zd\n", sizeof(*pf));
    printf("Sizeof malloc %zd\n", sizeof(struct flex) + n * sizeof(double));

    printf("%lld\n", (long long)pf);
    printf("%lld\n", (long long)&pf->count);
    printf("%zd\n", sizeof(pf->count));
    printf("%lld\n", (long long)&pf->average);
    printf("Address of pf->values %lld\n", (long long)&pf->values);
    printf("Value of pf->values %lld\n", (long long)pf->values);
    printf("Sizeof pf->values %zd\n", sizeof(pf->values));  // VS������ ���� �߻������� ������ ���� ����� 0 ������ size_t�� padding���� 8����Ʈ average�� 8����Ʈ 16����Ʈ�� �Ҵ�Ǵµ� �ű⿡ �߰��� �޸𸮸� �� �޾Ƽ� values[]�κ��� ���۵Ǵ� �迭�μ� ����

    pf->count = n;        // �����Ҵ��� �ް� ���Ŀ��� �Ҵ���� ũ�⸦ �ٽ� �˱� ����� ������ �̷��� �����س��´�
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
     �׷��ٸ� ����� �����͸� �߰��ϰ� �����Ҵ��ϴ� �Ͱ� � ���̰� �ֳ�?
    struct nonflex
    {
        size_t count;
        double average;
        double *values;  // ������ �����̱⿡ �� ��ü�� �޸𸮸� �����ϸ� �����Ҵ� �迭((double*)malloc(sizeof(double) * n);)�� count, average�� ���ӵ� �ּҸ� ���� �ʴ´�. ��� ��ġ�ϴ��� �� �� ����. ���� ����ü�� �����ϴ� �޸𸮿� ������ ����� ����Ű�� �޸𸮰� �ָ� ������ �� �ִ�.
                         // flexible array member�� �� ��ü�δ� �޸𸮸� �������� ������ count, average�� ���ӵ� �ּҸ� ���´�
    };

    struct nonflex nf;
    nf.values = (double*)malloc(sizeof(double) * n);
    */

    /*
        ���� ����
        struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
        if(pf2 == NULL) exit(1);

        *pf2 = *pf;  // Don't copy flexible members(�����Ҵ� ���� �� 40������ ������� 16�̴�. �����Ϸ� ���忡���� ������ �õ����� �� 16����Ʈ�� ���縦 ���ش�. �����Ϸ� ���忡���� �����Ҵ��� �޾ұ� ������ �� ���� ����.), use memcpy() instead
        //memcpy�� ����ؼ� ��ü�� �޸𸮸� �������� �� �ִ�.
        free(pf);
        free(pf2);
    */
}