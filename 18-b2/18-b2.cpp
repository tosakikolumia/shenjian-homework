/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include <cmath>
using namespace std;

/* �Ӵ˴�������滻��֮�䣬����������Ķ��弰ʵ��
	1����������ȫ�ֱ���������const��#define��
	2���������������ϵͳͷ�ļ�
*/ 
//���μ��������
class integral
{
protected:
	double low, high;
	int number;
	const char* name;
public:
	integral();
    virtual double value() const = 0; //�麯�����������ʵ��
	friend istream& operator>>(istream& is, integral& s);
};
class integral_sin : public integral
{
public:
	integral_sin();
	double value() const;
	
};
class integral_cos : public integral
{
public:
	integral_cos();
	double value() const;
	
};
class integral_exp : public integral
{
public:
	integral_exp();
	double value() const;

};
integral::integral(){
	low = 0;
	high = 0;
	number = 0;
	name = "";
}
integral_sin::integral_sin() : integral() {
	name = "sinxdx";
}
double integral_sin::value() const
{
	int  i;
	double sum = 0;
	double weight = fabs(low - high) / number;//ÿС����
	for (i = 1; i <= number; i++) {
		sum += ((sin(low + i * weight)) * weight);
	}
	cout << "sinxdx["<<low<<"~"<<high<<"/n="<<number<<"] : "<<sum<<endl;

	return sum;
}
integral_cos::integral_cos() : integral() {
	name = "cosxdx";
	
}
double integral_cos::value() const
{
	int  i;
	double sum = 0;
	double weight = fabs(low - high) / number;//ÿС����
	for (i = 1; i <= number; i++) {
		sum += ((cos(low + i * weight)) * weight);
	}
	cout << "cosxdx[" << low << "~" << high << "/n=" << number << "] : "<<sum<<endl;
	return sum;
}
integral_exp::integral_exp() : integral() {
	name = "e^xdx";
	
}
double integral_exp::value() const
{
	int  i;
	double sum = 0;
	double weight = fabs(low - high) / number;//ÿС����
	for (i = 1; i <= number; i++) {
		sum += ((exp(low + i * weight)) * weight);
	}
	cout << "e^xdx[" << low << "~" << high << "/n=" << number << "] : "<<sum<<endl;
	return sum;
}
istream& operator>>(istream& is, integral& s) {
	while(1)
	{
		cout<<"������"<<s.name<<"�����ޡ����޼����仮������"<<endl;
		is >> s.low >> s.high >> s.number;
		if (is.fail() || s.number <= 0 || s.low > s.high) {
			cout << "�����������������룡" << endl;
			is.clear();
			is.ignore(65536, '\n');
		}
		else {
			break;
		}
	}
	return is;
}




/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����fun_integral��׼����˼��һ�£�integralӦ��ζ���
***************************************************************************/
void fun_integral(integral& fRef)
{
	cin >> fRef;	//���������ޡ�������
	cout << fRef.value() << endl;
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;

	fun_integral(s1); //����sinxdx��ֵ
	fun_integral(s2); //����cosxdx��ֵ
	fun_integral(s3); //����expxdx��ֵ

	return 0;
}

//ע�����μ���ȡ��ֵ�����Ϊ����double��ʽ

