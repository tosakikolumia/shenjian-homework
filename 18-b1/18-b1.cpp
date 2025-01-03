/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include <cmath>
using namespace std;
#define MY_PI 3.14159
class Shape {
protected:
    //������Ҫ������Ӧ�ĳ�Ա��Ҳ����Ϊ��
public:
    virtual void ShapeName() = 0; //�˾䲻׼��
    //������Ҫ������Ӧ�ĳ�Ա��Ҳ����Ϊ��
    virtual double area() = 0; 
};

//�˴����������Ķ��弰ʵ��(��Ա������������ʵ����ʽ)
/*����*/
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r);
    double area();
    void ShapeName();
};
class Square : public Shape {
private:
    double side;
public:
    Square(double s);
    double area();
    void ShapeName();
};
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w);
    double area();
    void ShapeName();
};
class Trapezoid : public Shape {
private:
    double top_base;
    double bottom_base;
    double height;
public:
    Trapezoid(double tb, double bb, double h);
    double area();
    void ShapeName();
};
class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;
public:
    Triangle(double s1, double s2, double s3);
    double area();
    void ShapeName();
};
/*ʵ��*/
Circle::Circle(double r) {
    if (r <= 0) {
        radius = 0;
    } else {
        radius = r;
    }
}
double Circle::area() {
    if (radius <= 0) {
        return 0;
    } else {
        return MY_PI * radius * radius;
    }
}
void Circle::ShapeName() {
    cout << "Circle" << endl;
}
Square::Square(double s) {
    if (s <= 0) {
        side = 0;
    } else {
        side = s;
    }
}
double Square::area() {
    if (side <= 0) {
        return 0;
    } else {
        return side * side;
    }
}
void Square::ShapeName() {
    cout << "Square" << endl;
}
Rectangle::Rectangle(double l, double w) {
    if (l <= 0 || w <= 0) {
        length = 0;
        width = 0;
    } else {
        length = l;
        width = w;
    }
}
double Rectangle::area() {
    if (length <= 0 || width <= 0) {
        return 0;
    } else {
        return length * width;
    }
}
void Rectangle::ShapeName() {
    cout << "Rectangle" << endl;
}
Trapezoid::Trapezoid(double tb, double bb, double h) {
    if (tb <= 0 || bb <= 0 || h <= 0) {
        top_base = 0;
        bottom_base = 0;
        height = 0;
    } else {
        top_base = tb;
        bottom_base = bb;
        height = h;
    }
}
double Trapezoid::area() {
    if (top_base <= 0 || bottom_base <= 0 || height <= 0) {
        return 0;
    } else {
        return 0.5 * (top_base + bottom_base) * height;
    }
}
void Trapezoid::ShapeName() {
    cout << "Trapezoid" << endl;
}
Triangle::Triangle(double s1, double s2, double s3) {
    if (s1 <= 0 || s2 <= 0 || s3 <= 0 || s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
        side1 = 0;
        side2 = 0;
        side3 = 0;
    } else {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }
}
double Triangle::area() {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        return 0;
    } else {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
}
void Triangle::ShapeName() {
    cout << "Triangle" << endl;
}
/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������������main�����Ĵ��¿�ܣ��������΢����ı��ֵ
***************************************************************************/
int main()
{
    if (1) {
        Circle    c1(5.2);           //�뾶�����<=0�����Ϊ0��
        Square    s1(5.2);           //�߳������<=0�����Ϊ0��
        Rectangle r1(5.2, 3.7);      //�����������һ<=0�����Ϊ0��
        Trapezoid t1(2.3, 4.4, 3.8); //�ϵס��µס��ߣ������һ<=0�����Ϊ0��
        Triangle  t2(3, 4, 5);       //���߳��ȣ������һ<=0�򲻹��������Σ����Ϊ0��
        Shape* s[5] = { &c1, &s1, &r1, &t1, &t2 };

        int   i;
        for (i = 0; i < 5; i++) {
            s[i]->ShapeName(); //�ֱ��ӡ��ͬ��״ͼ�ε����ƣ���ʽ�ο�demo��
            cout << s[i]->area() << endl; //�ֱ��ӡ��ͬ��״ͼ�ε��������ʽ�ο�demo��
            cout << endl;
        }
    }

    if (1) {
        Circle    c1(-1);           //�뾶�����<=0�����Ϊ0��
        Square    s1(-1);           //�߳������<=0�����Ϊ0��
        Rectangle r1(5.2, -1);      //�����������һ<=0�����Ϊ0��
        Trapezoid t1(2.3, -1, 3.8); //�ϵס��µס��ߣ������һ<=0�����Ϊ0��
        Triangle  t2(3, 4, -1);       //���߳��ȣ������һ<=0�򲻹��������Σ����Ϊ0��
        Shape* s[5] = { &c1, &s1, &r1, &t1, &t2 };

        cout << "============" << endl;
        int   i;
        for (i = 0; i < 5; i++) {
            s[i]->ShapeName(); //�ֱ��ӡ��ͬ��״ͼ�ε����ƣ���ʽ�ο�demo��
            cout << s[i]->area() << endl; //�ֱ��ӡ��ͬ��״ͼ�ε��������ʽ�ο�demo��
            cout << endl;
        }
    }

    return 0;
}

