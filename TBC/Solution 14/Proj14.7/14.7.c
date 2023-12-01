/* ����ü�� �Լ��� �����ϴ� ��� */
#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
    char bank_name[FUNDLEN];
    double bank_saving;
    char fund_name[FUNDLEN];
    double fund_invest;
};
//signature�� body�� ���� ���� �� parameter�� �����ϱ� ������ �� �ִ�. �̶� change signature�� ��� �̰� function �̸��� �巡���ؾ� ��
//double sum(double, double);    // ��� 1
//double sum(double*, double*);  // ��� 2
//double sum(struct fortune mf);  // ��� 3(����ü�� �� ���縦 �����ϹǷ� ����ü ���� �����Ͱ� �ſ� ū ��� �޸𸮸� �����ϰ� �ǰ� ū �������� ����� ���� �ӵ��� ������ �� �ִ�)
double sum(const struct fortune* mf);  // ��� 4

int main(void)
{
    struct fortune my_fortune = {
        "Wells-Fargo",
        4032.27,
        "JPMorgan Chase",
        8543.94
    };

    printf("Total : $%.2F.\n",  // &mf identifier "mf" is undefined step into�ϸ� �ּҰ� ����
        //sum(my_fortune.bank_saving, my_fortune.fund_invest));    // ��� 1
        //sum(&my_fortune.bank_saving, &my_fortune.fund_invest));  // ��� 2 ���� �� ���� ������ ���ŷӴ�. sum���� my_fortune�� �����ְ� ���ο��� bank_saving fund_invest�� �����ָ� ������ ������?
        //sum(my_fortune));                                           // ��� 3
        sum(&my_fortune));                                        // ��� 4
    return 0;
}

//double sum(double x, double y) {           // ��� 1
//double sum(double* x, double* y) {         // ��� 2
//double sum(struct fortune mf) {    // ��� 3 debugger�� watch1�� &my_fortune�� ������� �� �ּҰ� f11��  step into�� �Ŀ� �ּҰ� �ٸ� ���� Ȯ�� ���� my_fortune�� value�� �ް� �ִ�. 14.6c ������� ������ ���� ���簡 �� argument�� �־�� my_fortune�� parameter�� �����ϰ� �� argument�� parameter�� �ּҰ� �ٸ���. �Լ��� �Ͻ������� stack�� fortune �޸𸮸� �ϳ� �� ������ �����Ͱ� ū ��� ������ �� �ִ�. �׸��� fortune�� ����� *arr�� �ְ� �����Ҵ��Ѵٸ� �ּҸ� ����ȴ�. 14.6c
double sum(const struct fortune* mf) {        // ��� 4 �׷��� �̰� ���� �� ���� ���ؼ� �����ҷ��� ���� ������� ���� �ٲܷ��� ���� �ƴϱ⿡ �տ� const�� �� ���δ�.
    //return x + y;                            // ��� 1
    //return *x + *y;                          // ��� 2 �̰�� �ٸ� ���α׷��Ӱ� *x = 0.0f; �� �ع����ٸ� ���� ���� �� �ִ�. sum(const double* x, const double* y)�� �صδ� ���� ���� �Ǽ� ����
    //return mf.bank_saving + mf.fund_invest; // ��� 3 
    return mf->bank_saving + mf->fund_invest;  // ��� 4
}