/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS //�رհ�ȫ�Ծ���
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#if defined _MSC_VER
#include <conio.h>
#elif defined __MINGW32__
#include <conio.h>
#endif
//������Ҫ�ɼ�������ͷ�ļ�
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
   1�����������ĺ����������������µ� FILE* �����д�/��/д/�رյȲ���
   2����������ͬ��������main����
*/
int usage(const char* const procname)
{
    printf("Usage : %s --modify | --read\n", procname);
    return 0;
}
//ʾ����������ӡdemo�ṹ������
void print_demo(const struct demo* player) {
    printf("%20s%s\n", "����ǳƣ�", player->name);
    printf("%20s%hd\n", "����ֵ��", player->hp);
    printf("%20s%hd\n", "����ֵ��", player->power);
    printf("%20s%hd\n", "����ֵ��", player->defence);
    printf("%20s%hd\n", "����ֵ��", player->Dexterity);
    printf("%20s%d\n", "��Ǯֵ��", player->money);
    printf("%20s%d\n", "����ֵ��", player->fame);
    printf("%20s%d\n", "����ֵ��", player->charm);
    printf("%20s%lld\n", "��Ϸ�ۼ�ʱ��(us)ֵ��", player->time);
    printf("%20s%d\n", "�ƶ��ٶ�ֵ��", (int)(player->move_speed));
    printf("%20s%d\n", "�����ٶ�ֵ��", (int)(player->attack_speed));
    printf("%20s%d\n", "������Χֵ��", (int)(player->attack_range));
    printf("%20s%hd\n", "������ֵ��", player->attack_power);
    printf("%20s%hd\n", "������ֵ��", player->defence_power);
    printf("%20s%d\n", "���ݶ�ֵ��", (int)(player->agility));
    printf("%20s%d\n", "����ֵ��", (int)(player->intelligence));
    printf("%20s%d\n", "����ֵ��", (int)(player->experience));
    printf("%20s%d\n", "�ȼ�ֵ��", (int)(player->level));
    printf("%20s%hd\n", "ħ��ֵ��", player->magicPoints);
    printf("%20s%d\n", "����ħ��ֵ��", (int)(player->magicCost));
    printf("%20s%d\n", "ħ���˺���ֵ��", (int)(player->magicDamage));
    printf("%20s%d\n", "������ֵ��", (int)(player->hitRate));
    printf("%20s%d\n", "ħ��������ֵ��", (int)(player->magicDefense));
    printf("%20s%d\n", "������ֵ��", (int)(player->criticalHitRate));
    printf("%20s%d\n", "����ֵ��", (int)(player->stamina));
}
//ʾ���������޸�demo�ṹ������
void modify_demo(struct demo* player)//�޸�demo�ṹ��
{
    printf("--------------------------------------\n");
    printf("  ��Ϸ�浵�ļ��޸Ĺ���\n");
    printf("--------------------------------------\n");
    printf("%-16s(%s)\n", "  a.����ǳ�", player->name);
    printf("%-16s(%d)\n", "  b.����", player->hp);
    printf("%-16s(%d)\n", "  c.����", player->power);
    printf("%-16s(%d)\n", "  d.����", player->defence);
    printf("%-16s(%d)\n", "  e.����", player->Dexterity);
    printf("%-16s(%d)\n", "  f.��Ǯ", player->money);
    printf("%-16s(%d)\n", "  g.����", player->fame);
    printf("%-16s(%d)\n", "  h.����", player->charm);
    printf("%-16s(%lld)\n", "  i.��Ϸ�ۼ�ʱ��", player->time);
    printf("%-16s(%d)\n", "  j.�ƶ��ٶ�", (int)(player->move_speed));
    printf("%-16s(%d)\n", "  k.�����ٶ�", (int)(player->attack_speed));
    printf("%-16s(%d)\n", "  l.������Χ", (int)(player->attack_range));
    printf("%-16s(%d)\n", "  m.������", player->attack_power);
    printf("%-16s(%d)\n", "  n.������", player->defence_power);
    printf("%-16s(%d)\n", "  o.���ݶ�", (int)(player->agility));
    printf("%-16s(%d)\n", "  p.����", (int)(player->intelligence));
    printf("%-16s(%d)\n", "  q.����", (int)(player->experience));
    printf("%-16s(%d)\n", "  r.�ȼ�", (int)(player->level));
    printf("%-16s(%d)\n", "  s.ħ��ֵ", player->magicPoints);
    printf("%-16s(%d)\n", "  t.����ħ��ֵ", (int)(player->magicCost));
    printf("%-16s(%d)\n", "  u.ħ���˺���", (int)(player->magicDamage));
    printf("%-16s(%d)\n", "  v.ħ��������", (int)(player->hitRate));
    printf("%-16s(%d)\n", "  w.ħ��������", (int)(player->magicDefense));
    printf("%-16s(%d)\n", "  x.������", (int)(player->criticalHitRate));
    printf("%-16s(%d)\n", "  y.����", player->stamina);
    printf("--------------------------------------\n");
    printf("  0.�����޸�\n");
    printf("  1.�����˳�\n");
    printf("--------------------------------------\n");
    printf("��ѡ��[a..y, 0..1] ");
}
void judge_modify_short(short* value, const short min, const short  max, const char* const prompt)
{
    while (1) {
        char ch;
        long long int temp;
        /*cout << prompt << "����ǰֵ=" << static_cast<long long>(value) << ", ��Χ[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "�������� : ";
        cin >> temp;*/
        printf("%s����ǰֵ=%hd����Χ[%d..%d]�������� : ", prompt, *value, min, max);
        int ret = scanf("%lld", &temp);
        if (!ret) {
            while ((ch = getchar()) != '\n');
            continue;
        }
        else {
            if (temp < SHRT_MIN || temp > SHRT_MAX) {
                while ((ch = getchar()) != '\n');
                continue;
            }
            if (temp < min || temp>max) {
                printf("�Ƿ���%sֵ��%d\n", prompt, (int)temp);
                while ((ch = getchar()) != '\n');
            }
            else {
                *value = (short)temp;
                break;
            }
        }
    }
}
void judge_modify_int(int* value, const int min, const int  max, const char* const prompt)
{
    while (1) {
        char ch;
        long long int temp;
        /*cout << prompt << "����ǰֵ=" << static_cast<long long>(value) << ", ��Χ[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "�������� : ";
        cin >> temp;2147483648*/
        printf("%s����ǰֵ=%d����Χ[%d..%d]�������� : ", prompt, *value, min, max);
        int ret = scanf("%lld", &temp);
        if (!ret) {
            while ((ch = getchar()) != '\n');
            continue;
        }
        else {
            if (temp < INT_MIN || temp > INT_MAX) {
                while ((ch = getchar()) != '\n');
                continue;
            }
            if (temp < min || temp>max) {
                printf("�Ƿ���%sֵ��%d\n", prompt, (int)temp);
                while ((ch = getchar()) != '\n');
            }
            else {
                *value = (int)temp;
                break;
            }
        }
    }
}
void judge_modify_long(long long* value, const long long min, const long long  max, const char* const prompt)
{
    while (1) {
        char ch;
        long long temp;
        /*cout << prompt << "����ǰֵ=" << static_cast<long long>(value) << ", ��Χ[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "�������� : ";
        cin >> temp;2147483648*/
        printf("%s����ǰֵ=%lld����Χ[%lld..%lld]�������� : ", prompt, *value, min, max);
        int ret = scanf("%lld", &temp);
        if (!ret) {
            while ((ch = getchar()) != '\n');
            continue;
        }
        else {
            if (temp < LLONG_MIN || temp > LLONG_MAX) {
                while ((ch = getchar()) != '\n');
                continue;
            }
            if (temp < min || temp>max) {
                printf("�Ƿ���%sֵ��%lld\n", prompt, temp);
                while ((ch = getchar()) != '\n');
            }
            else {
                *value = temp;
                break;
            }
        }
    }
}
void judge_modify_char(char* value, const int min, const int  max, const char* const prompt)
{
    while (1) {
        char ch;
        long long int temp;
        /*cout << prompt << "����ǰֵ=" << static_cast<long long>(value) << ", ��Χ[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "�������� : ";
        cin >> temp;*/
        printf("%s����ǰֵ=%d����Χ[%d..%d]�������� : ", prompt, (int)*value, min, max);
        int ret = scanf("%lld", &temp);
        if (!ret) {
            while ((ch = getchar()) != '\n');
            continue;
        }
        else {
            if (temp < INT_MIN || temp > INT_MAX) {
                while ((ch = getchar()) != '\n');
                continue;
            }
            if (temp < min || temp>max) {
                printf("�Ƿ���%sֵ��%d\n", prompt, (int)temp);
                while ((ch = getchar()) != '\n');
            }
            else {
                *value = (char)temp;
                break;
            }
        }
    }
}
int write_demo(struct demo* player)
{

    int save = 0;
    int loop = 1;
    while (loop) {
        char ch;
        modify_demo(player);
        char choice;
#if defined _MSC_VER
        choice = _getch();
#elif defined __MINGW32__
        choice = _getch();
#else
        choice = getchar();
#endif
        printf("\n");
        printf("\n");
        if (choice >= 'A' && choice <= 'Z') {
            choice = choice - 'A' + 'a';//ת��ΪСд
        }
        switch (choice) {
            case 'a':
                printf("����ǳƣ���ǰֵ=%s�������� : ", player->name);
                char temp[16];
                scanf("%s", temp);
                temp[15] = '\0';
                strncpy(player->name, temp, 16);
                while ((ch = getchar()) != '\n');
                break;
            case 'b':
                judge_modify_short(&player->hp, 0, 10000, "����");
                break;
            case 'c':
                judge_modify_short(&player->power, 0, 10000, "����");
                break;
            case 'd':
                judge_modify_short(&player->defence, 0, 8192, "����");
                break;
            case 'e':
                judge_modify_short(&player->Dexterity, 0, 1024, "����");
                break;
            case 'f':
                judge_modify_int(&player->money, 0, 100000000, "��Ǯ");
                break;
            case 'g':
                judge_modify_int(&player->fame, 0, 1000000, "����");
                break;
            case 'h':
                judge_modify_int(&player->charm, 0, 1000000, "����");
                break;
            case 'i':
                judge_modify_long(&player->time, 0, 10000000000000000, "��Ϸ�ۼ�ʱ��");
                break;
            case 'j':
                judge_modify_char(&player->move_speed, 0, 100, "�ƶ��ٶ�");
                break;
            case 'k':
                judge_modify_char(&player->attack_speed, 0, 100, "�����ٶ�");
                break;
            case 'l':
                judge_modify_char(&player->attack_range, 0, 100, "������Χ");
                break;
            case'm':
                judge_modify_short(&player->attack_power, 0, 2000, "������");
                break;
            case 'n':
                judge_modify_short(&player->defence_power, 0, 2000, "������");
                break;
            case 'o':
                judge_modify_char(&player->agility, 0, 100, "���ݶ�");
                break;
            case 'p':
                judge_modify_char(&player->intelligence, 0, 100, "����");
                break;
            case 'q':
                judge_modify_char(&player->experience, 0, 100, "����");
                break;
            case 'r':
                judge_modify_char(&player->level, 0, 100, "�ȼ�");
                break;
            case's':
                judge_modify_short(&player->magicPoints, 0, 10000, "ħ��ֵ");
                break;
            case 't':
                judge_modify_char(&player->magicCost, 0, 100, "����ħ��ֵ");
                break;
            case 'u':
               /* judge_modify(player.magicDamage, 0, 100, "ħ���˺���");*/
               judge_modify_char(&player->magicDamage, 0, 100, "ħ���˺���");
                break;
            case 'v':
                judge_modify_char(&player->hitRate, 0, 100, "������");
                break;
            case 'w':
               judge_modify_char(&player->magicDefense, 0, 100, "ħ��������");
                break;
            case 'x':
                judge_modify_char(&player->criticalHitRate, 0, 100, "������");
                break;
            case 'y':
                judge_modify_char(&player->stamina, 0, 100, "����");
                break;
            case '0':
                loop = 0;
                save = 0;
                break;
            case '1':
                loop = 0;
                save = 1;
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
  ˵    ��������������ֻ�������һ��fopen��һ��fread����Ϊ����������������fclose��
***************************************************************************/
int read(struct demo* player)
{
    /* ��������ֻ������һ�� FILE* */
    FILE* fp;

    /* �ļ��򿪣�����Ҫ��Ϊ��
       1��Ҫ���Զ���ʽ�򿪣��򿪷�ʽ***����ָ��
       2��������fopen�⣬�����������ط��������ٳ���fopen/freopen  */
    fp = fopen("game.dat", "rb");
    if (fp == NULL) {
        printf("�޷����ļ� game.dat\n");
        return -1;
    }
    /* ���к����������������������ļ�����ʾ����Ϸ���ֵ���ر��ļ��ȣ�������ú���
       ���У�ֻ������һ���Զ�ȡ64�ֽڵķ�����game.dat�����ݶ���***�����������ơ��ṹ����������ָ����
                 fread(***, 1, sizeof(demo), fp);
    */
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize != sizeof(struct demo)) {
        printf("�ļ�game.dat���ֽڴ�С����ȷ\n");
        return -1;
    }
    fseek(fp, 0, SEEK_SET);
    fread(player, 1, sizeof(struct demo), fp);
    fclose(fp);
    print_demo(player);
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ��������������ֻ�������һ��open��һ��read��һ��write����Ϊ����������������fclose��
***************************************************************************/
int modify(struct demo* player)
{
    /* ��������ֻ������һ�� FILE* */
    FILE* fp;

    /* �ļ��򿪣�����Ҫ��Ϊ��
       1��Ҫ���Զ�д��ʽ�򿪣��򿪷�ʽ***����ָ��
       2��������fopen�⣬�����������ط��������ٳ���fopen/freopen  */
    fp = fopen("game.dat", "rb+");
    if (fp == NULL) {
        printf("�޷����ļ� game.dat\n");
        return -1;
    }
    /* ���к����������������������ļ�����ʾ����Ϸ���ֵ���ر��ļ��ȣ�������ú���
       ���У�ֻ������һ���Զ�ȡ64�ֽڵķ�����game.dat�����ݶ���***�����������ơ��ṹ����������ָ����
                 fread(***, 1, sizeof(demo), fp);
             ֻ������һ����д��64�ֽڵķ�����***������д��game.dat�У����������ơ��ṹ����������ָ����
                 fwrite(***, 1, sizeof(demo), fp);
    */
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize != sizeof(struct demo)) {
        printf("�ļ� game.dat ���ֽڴ�С����ȷ\n");
        fclose(fp);
        return 1;
    }
    fseek(fp, 0, SEEK_SET);
    fread(player, 1, sizeof(struct demo), fp);
    int save = write_demo(player);
    fseek(fp, 0, SEEK_SET);
    if (save) {
        // д��ṹ������
        fwrite(player, sizeof(struct demo), 1, fp);
    }
    fclose(fp); // �ر��ļ�
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��9223372036854775807 
  ˵    ����main�������������������������ļ���д
***************************************************************************/
int main(int argc, char** argv)
{
    struct demo player;
    /*cout<<sizeof(player)<<endl;*/
    if (argc == 2) { /* ���в����������ȡ����ֵ���޸���Ϸ���ݵ� */
        if (strcmp(argv[1], "--read") == 0) {
            read(&player);
        }
        else if (strcmp(argv[1], "--modify") == 0) {
            modify(&player);
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