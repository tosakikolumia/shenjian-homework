/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#if defined _MSC_VER
#include <conio.h>
#elif defined __MINGW32__
#include <conio.h>
#endif

//������Ҫ�ɼ�������ͷ�ļ�
using namespace std;

//�˴�Ϊʾ���������޸Ľṹ�����ƣ������޸Ľṹ���еĳ�Ա���ݣ�Ҫ��sizeof������64
#pragma pack(1)
struct demo {
    char name[16];//����
    short hp;//Ѫ��0-10000
    short power;//����0-10000
    short defence;//����0-8192
    short Dexterity;//����0-1024
    int money;//��Ǯ0-1*10^8
    int fame;//����0-1*10^6
    int charm;//����0-1*10^6
    long long time;//�ۼ�ʱ��1*10^16
    char move_speed;// �ƶ��ٶ�0-100
    char attack_speed;//�����ٶ�0-100
    char attack_range;//������Χ0-100
    char attach;//Ԥ��
    short attack_power;//������0-2000
    short defence_power;//������0-2000
    char agility;//���ݶ�0-100
    char intelligence;//����0-100
    char experience;//����0-100
    char level;//�ȼ�0-100
    short magicPoints;//ħ��ֵ0-10000
    char magicCost;//ħ������0-100
    char magicDamage;//ħ���˺�0-100
    char hitRate;//������0-100
    char magicDefense;//ħ������0-100
    char criticalHitRate;//������0-100
    char stamina;//����0-100
};

/* �˴�����������������������
   1�����������ĺ����������������µ� fstream / ifstream / ofstream �����󣬲����д�/��/д/�رյȲ���
   2�����������ĺ���������������C��ʽ�����ļ�����
   3��������������ͬ��������main����
*/
int usage(const char* const procname)
{
    cout << "Usage : " << procname << " --modify | --read" << endl;
    return 0;
}
void print_demo(struct demo& player)//��ӡ�����Ϣ
{
    cout << setw(20) << "����ǳƣ�" << player.name << endl;
    cout << setw(20) << "����ֵ��" << player.hp << endl;
    cout << setw(20) << "����ֵ��" << player.power << endl;
    cout << setw(20) << "����ֵ��" << player.defence << endl;
    cout << setw(20) << "����ֵ��" << player.Dexterity << endl;
    cout << setw(20) << "��Ǯֵ��" << player.money << endl;
    cout << setw(20) << "����ֵ��" << player.fame << endl;
    cout << setw(20) << "����ֵ��" << player.charm << endl;
    cout << setw(20) << "��Ϸ�ۼ�ʱ��(us)ֵ��" << player.time << endl;
    cout << setw(20) << "�ƶ��ٶ�ֵ��" << int(player.move_speed) << endl;
    cout << setw(20) << "�����ٶ�ֵ��" << int(player.attack_speed) << endl;
    cout << setw(20) << "������Χֵ��" << int(player.attack_range) << endl;
    cout << setw(20) << "������ֵ��" << player.attack_power<< endl;
    cout << setw(20) << "������ֵ��" << player.defence_power<< endl;
    cout << setw(20) << "���ݶ�ֵ��" << int(player.agility) << endl;
    cout << setw(20) << "����ֵ��" << int(player.intelligence) << endl;
    cout << setw(20) << "����ֵ��" << int(player.experience) << endl;
    cout << setw(20) << "�ȼ�ֵ��" << int (player.level) << endl;
    cout << setw(20) << "ħ��ֵ��" << player.magicPoints << endl;
    cout << setw(20) << "����ħ��ֵ��" << int(player.magicCost) << endl;
    cout << setw(20) << "ħ���˺���ֵ��" << int(player.magicDamage) << endl;
    cout << setw(20) << "������ֵ��" << int(player.hitRate) << endl;
    cout << setw(20) << "ħ��������ֵ��" << int(player.magicDefense) << endl;
    cout << setw(20) << "������ֵ��" << int(player.criticalHitRate) << endl;
    cout << setw(20) << "����ֵ��" << int(player.stamina) << endl;
}

void modify_demo(struct demo& player)//�޸�demo�ṹ��
{
    cout<<"--------------------------------------"<<endl;
    cout<<"  ��Ϸ�浵�ļ��޸Ĺ���"<<endl;
    cout << "--------------------------------------" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  a.����ǳ�" << "(" << player.name << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  b.����" << "(" << player.hp << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  c.����" << "(" << player.power << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  d.����" << "(" << player.defence << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  e.����" << "(" << player.Dexterity << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  f.��Ǯ" << "(" << player.money << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  g.����" << "(" << player.fame << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  h.����" << "(" << player.charm << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  i.��Ϸ�ۼ�ʱ��" << "(" << player.time << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  j.�ƶ��ٶ�" << "(" << int(player.move_speed) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  k.�����ٶ�" << "(" << int(player.attack_speed) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  l.������Χ" << "(" << int(player.attack_range) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  m.������" << "(" << player.attack_power << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  n.������" << "(" << player.defence_power << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  o.���ݶ�" << "(" << int(player.agility) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  p.����" << "(" << int(player.intelligence) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  q.����" << "(" << int(player.experience) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  r.�ȼ�" << "(" << int(player.level) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  s.ħ��ֵ" << "(" << player.magicPoints << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  t.����ħ��ֵ" << "(" << int(player.magicCost) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  u.ħ���˺���" << "(" << int(player.magicDamage) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  v.ħ��������" << "(" << int(player.hitRate) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  w.ħ��������" << "(" << int(player.magicDefense) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  x.������" << "(" << int(player.criticalHitRate) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  y.����" << "(" << int(player.stamina) << ")" << endl;
    cout << "--------------------------------------" << endl;
    cout << "  0.�����޸�" << endl;
    cout << "  1.�����˳�" << endl;
    cout << "--------------------------------------" << endl;
    cout << "��ѡ��[a..y, 0..1] ";
}

template<typename T>
void judge_modify(T& value, int min ,int max,const char* const prompt)
{  
    if (typeid(T) == typeid(long long)) {
        while (1) {
            long long temp;
            cout << prompt << "����ǰֵ=" << static_cast<long long>(value) << ", ��Χ[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "�������� : ";
            cin >> temp;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(65536, '\n');
            }
            else {
                if (temp < min || temp > max) {
                    cout << "�Ƿ���" << prompt << "ֵ��" << temp << endl;
                    cin.clear();
                    cin.ignore(65536, '\n');
                }
                else {
                    value = T(temp);
                    break;
                }
            }
        }
    }
    else {
        while (1) {
            int temp;
            cout << prompt << "����ǰֵ=" << static_cast<int>(value) << ", ��Χ[" << static_cast<int>(min) << ".." << static_cast<int>(max) << "]" << "�������� : ";
            cin >> temp;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(65536, '\n');
            }
            else {
                if (temp < min || temp > max) {
                    cout << "�Ƿ���" << prompt << "ֵ��" << temp << endl;
                    cin.clear();
                    cin.ignore(65536, '\n');
                }
                else {
                    value = T(temp);
                    break;
                }
            }
        }
    }
}
   
bool write_demo(struct demo& player)
{
    bool save = false;
    bool loop = true;
    while (loop) {
        modify_demo(player);
        char choice;
#if defined _MSC_VER
        choice = _getch();
#elif defined __MINGW32__
        choice = _getch();
#else
        choice = getchar();
#endif
        cout << endl;
        cout << endl;
        if (choice >= 'A' && choice <= 'Z') {
            choice = choice - 'A' + 'a';//ת��ΪСд
        }
        switch (choice) {
            case 'a':
                cout << "����ǳ�" << "����ǰֵ=" << player.name << "�������� : " ;
                char temp[16];
                cin >> temp;
                temp[15] = '\0';
                strncpy(player.name, temp, 16);
                cin.clear();
                cin.ignore(65536, '\n');
                break;
            case 'b':
                judge_modify(player.hp, 0, 10000, "����");
                break;
            case 'c':
                judge_modify(player.power, 0, 10000, "����");
                break;
            case 'd':
                judge_modify(player.defence, 0, 8192, "����");
                break;
            case 'e':
                judge_modify(player.Dexterity, 0, 1024, "����");
                break;
            case 'f':
                judge_modify(player.money, 0, 10000000, "��Ǯ");
                break;
            case 'g':
                judge_modify(player.fame, 0, 1000000, "����");
                break;
            case 'h':
                judge_modify(player.charm, 0, 1000000, "����");
                break;
            case 'i':
                judge_modify(player.time, 0, 10000000 ,"��Ϸ�ۼ�ʱ��");
                break;
            case 'j':
                judge_modify(player.move_speed, 0, 100, "�ƶ��ٶ�");
                break;
            case 'k':
                judge_modify(player.attack_speed, 0, 100, "�����ٶ�");
                break;
            case 'l':
                judge_modify(player.attack_range, 0, 100, "������Χ");
                break;
            case'm':
                judge_modify(player.attack_power, 0, 2000, "������");
                break;
            case 'n':
                judge_modify(player.defence_power, 0, 2000, "������");
                break;
            case 'o':
                judge_modify(player.agility, 0, 100, "���ݶ�");
                break;
            case 'p':
                judge_modify(player.intelligence, 0, 100, "����");
                break;
            case 'q':
                judge_modify(player.experience, 0, 100, "����");
                break;
            case 'r':
                judge_modify(player.level, 0, 100, "�ȼ�");
                break;
            case's':
                judge_modify(player.magicPoints, 0, 10000, "ħ��");
                break;
            case 't':
                judge_modify(player.magicCost, 0, 100, "����ħ��");
                break;
            case 'u':
                judge_modify(player.magicDamage, 0, 100, "ħ���˺���");
                break;
            case 'v':
                judge_modify(player.hitRate, 0, 100, "������");
                break;
            case 'w':
                judge_modify(player.magicDefense, 0, 100, "ħ��������");
                break;
            case 'x':
                judge_modify(player.criticalHitRate, 0, 100, "������");
                break;
            case 'y':
                judge_modify(player.stamina, 0, 100, "����");
                break;
            case '0':
                loop = false;//�˳��޸�
                break;
            case '1':
                loop = false;//�˳��޸Ĳ�����
                save = true;//��Ǵ���
                break;
            default:
                break;
        }
    }
    return save;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ��������������ֻ�������һ��open��һ��read����Ϊ����������������close��
***************************************************************************/
int read(struct demo& player)
{
    /* ��������ֻ������һ�� ifstream�����󣬲����������κ���ʽ��fstream/ifstream/ofstream������Ҳ������ʹ��C��ʽ���ļ����� */
    ifstream gfile;

    /* �ļ��򿪣�����Ҫ��Ϊ��
       1��Ҫ���Զ���ʽ�򿪣��򿪷�ʽ***����ָ��
       2��������open�⣬�����������ط��������ٳ���open  */
    gfile.open("game.dat", ios::binary);
    if (!gfile) {
        cout << "�޷����ļ�game.dat" << endl;
        return 1;
    }
    if (gfile.seekg(0, ios::end).tellg() != 64) {
        cout << "�ļ�game.dat���ֽڴ�С����ȷ" << endl;
        gfile.close();
        return 1;
    }
    gfile.seekg(0, ios::beg);
    /* ���к����������������������ļ�����ʾ����Ϸ���ֵ���ر��ļ��ȣ�������ú���
       ���У�ֻ������һ���Զ�ȡ64�ֽڵķ�����game.dat�����ݶ���***�����������ơ��ṹ����������ָ����
                 gfile.read(***, sizeof(demo));
    */
    gfile.read((char*)&player, sizeof(demo));
    gfile.close();
    print_demo(player);
    return 0;

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ��������������ֻ�������һ��open��һ��read��һ��write����Ϊ����������������close��
***************************************************************************/
int modify(struct demo& player)
{
    /* ��������ֻ������һ�� fstream�����󣬲����������κ���ʽ��fstream/ifstream/ofstream������Ҳ������ʹ��C��ʽ���ļ����� */
    fstream gfile;

    /* �ļ��򿪣�����Ҫ��Ϊ��
       1��Ҫ���Զ�д��ʽ�򿪣��򿪷�ʽ***����ָ��
       2��������open�⣬�����������ط��������ٳ���open  */
    gfile.open("game.dat", ios::in | ios::out | ios::binary);
    if (!gfile) {
        cout << "�޷����ļ�game.dat" << endl;
        return 1;
    }
    if (gfile.seekg(0, ios::end).tellg() < 64) {
        cout << "�ļ�game.dat���ֽڴ�С����ȷ" << endl;
        gfile.close();
        return 1;
    }
    gfile.seekp(0, ios::beg);
    /* ���к����������������������ļ�����ʾ����Ϸ���ֵ���ر��ļ��ȣ�������ú���
       ���У�ֻ������һ���Զ�ȡ64�ֽڵķ�����game.dat�����ݶ���***�����������ơ��ṹ����������ָ����
                 gfile.read(***, sizeof(demo));
             ֻ������һ����д��64�ֽڵķ�����***������д��game.dat�У����������ơ��ṹ����������ָ����
                 gfile.write(***, sizeof(demo));
    */
    gfile.read((char*)&player, sizeof(demo));
    bool save = write_demo(player);
    gfile.seekp(0, ios::beg);
    gfile.clear();
    if (save) {
        gfile.write((char*)&player, sizeof(demo));
    }
    gfile.close();
    return 0;

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�������������������������ļ���д
***************************************************************************/
int main(int argc, char** argv)
{
   struct demo player;
   /*cout<<sizeof(player)<<endl;*/
   if (argc == 2) { /* ���в����������ȡ����ֵ���޸���Ϸ���ݵ� */
       if (strcmp(argv[1], "--read") == 0) {
           read(player);
       }
       else if (strcmp(argv[1], "--modify") == 0) {
           modify(player);
       }
       else {
           return usage(argv[0]);
       }
   }
   else {
       return usage(argv[0]);
   }
   return 0;
}