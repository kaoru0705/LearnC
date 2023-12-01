/* 구조체를 함수로 전달하는 방법 */
#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
    char bank_name[FUNDLEN];
    double bank_saving;
    char fund_name[FUNDLEN];
    double fund_invest;
};
//signature랑 body가 따로 있을 때 parameter를 변경하기 불편할 수 있다. 이때 change signature를 써라 이거 function 이름만 드래그해야 됨
//double sum(double, double);    // 방법 1
//double sum(double*, double*);  // 방법 2
//double sum(struct fortune mf);  // 방법 3(구조체는 값 복사를 수행하므로 구조체 내의 데이터가 매우 큰 경우 메모리를 낭비하게 되고 큰 데이터의 복사로 인해 속도가 느려질 수 있다)
double sum(const struct fortune* mf);  // 방법 4

int main(void)
{
    struct fortune my_fortune = {
        "Wells-Fargo",
        4032.27,
        "JPMorgan Chase",
        8543.94
    };

    printf("Total : $%.2F.\n",  // &mf identifier "mf" is undefined step into하면 주소가 생김
        //sum(my_fortune.bank_saving, my_fortune.fund_invest));    // 방법 1
        //sum(&my_fortune.bank_saving, &my_fortune.fund_invest));  // 방법 2 뭔가 두 개를 보내니 번거롭다. sum에다 my_fortune만 보내주고 내부에서 bank_saving fund_invest를 더해주면 편하지 않을까?
        //sum(my_fortune));                                           // 방법 3
        sum(&my_fortune));                                        // 방법 4
    return 0;
}

//double sum(double x, double y) {           // 방법 1
//double sum(double* x, double* y) {         // 방법 2
//double sum(struct fortune mf) {    // 방법 3 debugger로 watch1에 &my_fortune을 등록했을 때 주소가 f11로  step into한 후에 주소가 다른 것을 확인 가능 my_fortune을 value로 받고 있다. 14.6c 멤버들의 값들이 전부 복사가 됨 argument에 넣어둔 my_fortune을 parameter에 복사하게 됨 argument와 parameter의 주소가 다르다. 함수가 일시적으로 stack에 fortune 메모리를 하나 더 차지함 데이터가 큰 경우 느려질 수 있다. 그리고 fortune에 멤버로 *arr을 넣고 동적할당한다면 주소만 복사된다. 14.6c
double sum(const struct fortune* mf) {        // 방법 4 그래서 이걸 많이 씀 값을 더해서 전달할려는 거지 멤버들의 값을 바꿀려는 것은 아니기에 앞에 const를 꼭 붙인다.
    //return x + y;                            // 방법 1
    //return *x + *y;                          // 방법 2 이경우 다른 프로그래머가 *x = 0.0f; 를 해버린다면 값이 ㅈ될 수 있다. sum(const double* x, const double* y)로 해두는 것이 안전 실수 방지
    //return mf.bank_saving + mf.fund_invest; // 방법 3 
    return mf->bank_saving + mf->fund_invest;  // 방법 4
}