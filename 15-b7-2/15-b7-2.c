/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS //关闭安全性警告
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#if defined _MSC_VER
#include <conio.h>
#elif defined __MINGW32__
#include <conio.h>
#endif
//根据需要可加入其它头文件
//此处为示例，允许修改结构体名称，允许修改结构体中的成员内容，要求sizeof必须是64
#pragma pack(1)
struct demo {
    char name[16];//名称
    short hp;//血量0-10000
    short power;//力量0-10000
    short defence;//体质0-8192
    short Dexterity;//灵巧0-1024
    int money;//金钱0-1*10^8
    int fame;//名声0-1*10^6
    int charm;//魅力0-1*10^6
    long long time;//累计时间1*10^16
    char move_speed;// 移动速度0-100
    char attack_speed;//攻击速度0-100
    char attack_range;//攻击范围0-100
    char attach;//预留
    short attack_power;//攻击力0-2000
    short defence_power;//防御力0-2000
    char agility;//敏捷度0-100
    char intelligence;//智力0-100
    char experience;//经验0-100
    char level;//等级0-100
    short magicPoints;//魔法值0-10000
    char magicCost;//魔法消耗0-100
    char magicDamage;//魔法伤害0-100
    char hitRate;//命中率0-100
    char magicDefense;//魔法防御0-100
    char criticalHitRate;//暴击率0-100
    char stamina;//耐力0-100
};
/* 此处允许新增函数，数量不限
   1、所有新增的函数，均不允许定义新的 FILE* 并进行打开/读/写/关闭等操作
   2、上述限制同样适用于main函数
*/
int usage(const char* const procname)
{
    printf("Usage : %s --modify | --read\n", procname);
    return 0;
}
//示例函数，打印demo结构体内容
void print_demo(const struct demo* player) {
    printf("%20s%s\n", "玩家昵称：", player->name);
    printf("%20s%hd\n", "生命值：", player->hp);
    printf("%20s%hd\n", "力量值：", player->power);
    printf("%20s%hd\n", "体质值：", player->defence);
    printf("%20s%hd\n", "灵巧值：", player->Dexterity);
    printf("%20s%d\n", "金钱值：", player->money);
    printf("%20s%d\n", "名声值：", player->fame);
    printf("%20s%d\n", "魅力值：", player->charm);
    printf("%20s%lld\n", "游戏累计时间(us)值：", player->time);
    printf("%20s%d\n", "移动速度值：", (int)(player->move_speed));
    printf("%20s%d\n", "攻击速度值：", (int)(player->attack_speed));
    printf("%20s%d\n", "攻击范围值：", (int)(player->attack_range));
    printf("%20s%hd\n", "攻击力值：", player->attack_power);
    printf("%20s%hd\n", "防御力值：", player->defence_power);
    printf("%20s%d\n", "敏捷度值：", (int)(player->agility));
    printf("%20s%d\n", "智力值：", (int)(player->intelligence));
    printf("%20s%d\n", "经验值：", (int)(player->experience));
    printf("%20s%d\n", "等级值：", (int)(player->level));
    printf("%20s%hd\n", "魔法值：", player->magicPoints);
    printf("%20s%d\n", "消耗魔法值：", (int)(player->magicCost));
    printf("%20s%d\n", "魔法伤害力值：", (int)(player->magicDamage));
    printf("%20s%d\n", "命中率值：", (int)(player->hitRate));
    printf("%20s%d\n", "魔法防御力值：", (int)(player->magicDefense));
    printf("%20s%d\n", "暴击率值：", (int)(player->criticalHitRate));
    printf("%20s%d\n", "耐力值：", (int)(player->stamina));
}
//示例函数，修改demo结构体内容
void modify_demo(struct demo* player)//修改demo结构体
{
    printf("--------------------------------------\n");
    printf("  游戏存档文件修改工具\n");
    printf("--------------------------------------\n");
    printf("%-16s(%s)\n", "  a.玩家昵称", player->name);
    printf("%-16s(%d)\n", "  b.生命", player->hp);
    printf("%-16s(%d)\n", "  c.力量", player->power);
    printf("%-16s(%d)\n", "  d.体质", player->defence);
    printf("%-16s(%d)\n", "  e.灵巧", player->Dexterity);
    printf("%-16s(%d)\n", "  f.金钱", player->money);
    printf("%-16s(%d)\n", "  g.名声", player->fame);
    printf("%-16s(%d)\n", "  h.魅力", player->charm);
    printf("%-16s(%lld)\n", "  i.游戏累计时间", player->time);
    printf("%-16s(%d)\n", "  j.移动速度", (int)(player->move_speed));
    printf("%-16s(%d)\n", "  k.攻击速度", (int)(player->attack_speed));
    printf("%-16s(%d)\n", "  l.攻击范围", (int)(player->attack_range));
    printf("%-16s(%d)\n", "  m.攻击力", player->attack_power);
    printf("%-16s(%d)\n", "  n.防御力", player->defence_power);
    printf("%-16s(%d)\n", "  o.敏捷度", (int)(player->agility));
    printf("%-16s(%d)\n", "  p.智力", (int)(player->intelligence));
    printf("%-16s(%d)\n", "  q.经验", (int)(player->experience));
    printf("%-16s(%d)\n", "  r.等级", (int)(player->level));
    printf("%-16s(%d)\n", "  s.魔法值", player->magicPoints);
    printf("%-16s(%d)\n", "  t.消耗魔法值", (int)(player->magicCost));
    printf("%-16s(%d)\n", "  u.魔法伤害力", (int)(player->magicDamage));
    printf("%-16s(%d)\n", "  v.魔法命中率", (int)(player->hitRate));
    printf("%-16s(%d)\n", "  w.魔法防御力", (int)(player->magicDefense));
    printf("%-16s(%d)\n", "  x.暴击率", (int)(player->criticalHitRate));
    printf("%-16s(%d)\n", "  y.耐力", player->stamina);
    printf("--------------------------------------\n");
    printf("  0.放弃修改\n");
    printf("  1.存盘退出\n");
    printf("--------------------------------------\n");
    printf("请选择[a..y, 0..1] ");
}
void judge_modify_short(short* value, const short min, const short  max, const char* const prompt)
{
    while (1) {
        char ch;
        long long int temp;
        /*cout << prompt << "，当前值=" << static_cast<long long>(value) << ", 范围[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "，请输入 : ";
        cin >> temp;*/
        printf("%s，当前值=%hd，范围[%d..%d]，请输入 : ", prompt, *value, min, max);
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
                printf("非法的%s值：%d\n", prompt, (int)temp);
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
        /*cout << prompt << "，当前值=" << static_cast<long long>(value) << ", 范围[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "，请输入 : ";
        cin >> temp;2147483648*/
        printf("%s，当前值=%d，范围[%d..%d]，请输入 : ", prompt, *value, min, max);
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
                printf("非法的%s值：%d\n", prompt, (int)temp);
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
        /*cout << prompt << "，当前值=" << static_cast<long long>(value) << ", 范围[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "，请输入 : ";
        cin >> temp;2147483648*/
        printf("%s，当前值=%lld，范围[%lld..%lld]，请输入 : ", prompt, *value, min, max);
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
                printf("非法的%s值：%lld\n", prompt, temp);
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
        /*cout << prompt << "，当前值=" << static_cast<long long>(value) << ", 范围[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "，请输入 : ";
        cin >> temp;*/
        printf("%s，当前值=%d，范围[%d..%d]，请输入 : ", prompt, (int)*value, min, max);
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
                printf("非法的%s值：%d\n", prompt, (int)temp);
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
            choice = choice - 'A' + 'a';//转换为小写
        }
        switch (choice) {
            case 'a':
                printf("玩家昵称，当前值=%s，请输入 : ", player->name);
                char temp[16];
                scanf("%s", temp);
                temp[15] = '\0';
                strncpy(player->name, temp, 16);
                while ((ch = getchar()) != '\n');
                break;
            case 'b':
                judge_modify_short(&player->hp, 0, 10000, "生命");
                break;
            case 'c':
                judge_modify_short(&player->power, 0, 10000, "力量");
                break;
            case 'd':
                judge_modify_short(&player->defence, 0, 8192, "体质");
                break;
            case 'e':
                judge_modify_short(&player->Dexterity, 0, 1024, "灵巧");
                break;
            case 'f':
                judge_modify_int(&player->money, 0, 100000000, "金钱");
                break;
            case 'g':
                judge_modify_int(&player->fame, 0, 1000000, "名声");
                break;
            case 'h':
                judge_modify_int(&player->charm, 0, 1000000, "魅力");
                break;
            case 'i':
                judge_modify_long(&player->time, 0, 10000000000000000, "游戏累计时间");
                break;
            case 'j':
                judge_modify_char(&player->move_speed, 0, 100, "移动速度");
                break;
            case 'k':
                judge_modify_char(&player->attack_speed, 0, 100, "攻击速度");
                break;
            case 'l':
                judge_modify_char(&player->attack_range, 0, 100, "攻击范围");
                break;
            case'm':
                judge_modify_short(&player->attack_power, 0, 2000, "攻击力");
                break;
            case 'n':
                judge_modify_short(&player->defence_power, 0, 2000, "防御力");
                break;
            case 'o':
                judge_modify_char(&player->agility, 0, 100, "敏捷度");
                break;
            case 'p':
                judge_modify_char(&player->intelligence, 0, 100, "智力");
                break;
            case 'q':
                judge_modify_char(&player->experience, 0, 100, "经验");
                break;
            case 'r':
                judge_modify_char(&player->level, 0, 100, "等级");
                break;
            case's':
                judge_modify_short(&player->magicPoints, 0, 10000, "魔法值");
                break;
            case 't':
                judge_modify_char(&player->magicCost, 0, 100, "消耗魔法值");
                break;
            case 'u':
               /* judge_modify(player.magicDamage, 0, 100, "魔法伤害力");*/
               judge_modify_char(&player->magicDamage, 0, 100, "魔法伤害力");
                break;
            case 'v':
                judge_modify_char(&player->hitRate, 0, 100, "命中率");
                break;
            case 'w':
               judge_modify_char(&player->magicDefense, 0, 100, "魔法防御力");
                break;
            case 'x':
                judge_modify_char(&player->criticalHitRate, 0, 100, "暴击率");
                break;
            case 'y':
                judge_modify_char(&player->stamina, 0, 100, "耐力");
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次fopen、一次fread（因为包含错误处理，允许多次fclose）
***************************************************************************/
int read(struct demo* player)
{
    /* 本函数中只允许定义一个 FILE* */
    FILE* fp;

    /* 文件打开，具体要求为：
       1、要求以读方式打开，打开方式***自行指定
       2、除本次fopen外，本函数其它地方不允许再出现fopen/freopen  */
    fp = fopen("game.dat", "rb");
    if (fp == NULL) {
        printf("无法打开文件 game.dat\n");
        return -1;
    }
    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 fread(***, 1, sizeof(demo), fp);
    */
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize != sizeof(struct demo)) {
        printf("文件game.dat的字节大小不正确\n");
        return -1;
    }
    fseek(fp, 0, SEEK_SET);
    fread(player, 1, sizeof(struct demo), fp);
    fclose(fp);
    print_demo(player);
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read、一次write（因为包含错误处理，允许多次fclose）
***************************************************************************/
int modify(struct demo* player)
{
    /* 本函数中只允许定义一个 FILE* */
    FILE* fp;

    /* 文件打开，具体要求为：
       1、要求以读写方式打开，打开方式***自行指定
       2、除本次fopen外，本函数其它地方不允许再出现fopen/freopen  */
    fp = fopen("game.dat", "rb+");
    if (fp == NULL) {
        printf("无法打开文件 game.dat\n");
        return -1;
    }
    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 fread(***, 1, sizeof(demo), fp);
             只允许用一次性写入64字节的方法将***的内容写入game.dat中（缓冲区名称、结构体名称自行指定）
                 fwrite(***, 1, sizeof(demo), fp);
    */
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize != sizeof(struct demo)) {
        printf("文件 game.dat 的字节大小不正确\n");
        fclose(fp);
        return 1;
    }
    fseek(fp, 0, SEEK_SET);
    fread(player, 1, sizeof(struct demo), fp);
    int save = write_demo(player);
    fseek(fp, 0, SEEK_SET);
    if (save) {
        // 写入结构体数据
        fwrite(player, sizeof(struct demo), 1, fp);
    }
    fclose(fp); // 关闭文件
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：9223372036854775807 
  说    明：main函数允许带参数，不允许进行文件读写
***************************************************************************/
int main(int argc, char** argv)
{
    struct demo player;
    /*cout<<sizeof(player)<<endl;*/
    if (argc == 2) { /* 进行参数处理，如读取参数值、修改游戏数据等 */
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