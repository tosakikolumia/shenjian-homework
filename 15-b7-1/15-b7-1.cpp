/* 2351753 计科 黄保翔 */
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

//根据需要可加入其它头文件
using namespace std;

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
   1、所有新增的函数，均不允许定义新的 fstream / ifstream / ofstream 流对象，并进行打开/读/写/关闭等操作
   2、所有新增的函数，均不允许用C方式进行文件处理
   3、上述两个限制同样适用于main函数
*/
int usage(const char* const procname)
{
    cout << "Usage : " << procname << " --modify | --read" << endl;
    return 0;
}
void print_demo(struct demo& player)//打印玩家信息
{
    cout << setw(20) << "玩家昵称：" << player.name << endl;
    cout << setw(20) << "生命值：" << player.hp << endl;
    cout << setw(20) << "力量值：" << player.power << endl;
    cout << setw(20) << "体质值：" << player.defence << endl;
    cout << setw(20) << "灵巧值：" << player.Dexterity << endl;
    cout << setw(20) << "金钱值：" << player.money << endl;
    cout << setw(20) << "名声值：" << player.fame << endl;
    cout << setw(20) << "魅力值：" << player.charm << endl;
    cout << setw(20) << "游戏累计时间(us)值：" << player.time << endl;
    cout << setw(20) << "移动速度值：" << int(player.move_speed) << endl;
    cout << setw(20) << "攻击速度值：" << int(player.attack_speed) << endl;
    cout << setw(20) << "攻击范围值：" << int(player.attack_range) << endl;
    cout << setw(20) << "攻击力值：" << player.attack_power<< endl;
    cout << setw(20) << "防御力值：" << player.defence_power<< endl;
    cout << setw(20) << "敏捷度值：" << int(player.agility) << endl;
    cout << setw(20) << "智力值：" << int(player.intelligence) << endl;
    cout << setw(20) << "经验值：" << int(player.experience) << endl;
    cout << setw(20) << "等级值：" << int (player.level) << endl;
    cout << setw(20) << "魔法值：" << player.magicPoints << endl;
    cout << setw(20) << "消耗魔法值：" << int(player.magicCost) << endl;
    cout << setw(20) << "魔法伤害力值：" << int(player.magicDamage) << endl;
    cout << setw(20) << "命中率值：" << int(player.hitRate) << endl;
    cout << setw(20) << "魔法防御力值：" << int(player.magicDefense) << endl;
    cout << setw(20) << "暴击率值：" << int(player.criticalHitRate) << endl;
    cout << setw(20) << "耐力值：" << int(player.stamina) << endl;
}

void modify_demo(struct demo& player)//修改demo结构体
{
    cout<<"--------------------------------------"<<endl;
    cout<<"  游戏存档文件修改工具"<<endl;
    cout << "--------------------------------------" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  a.玩家昵称" << "(" << player.name << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  b.生命" << "(" << player.hp << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  c.力量" << "(" << player.power << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  d.体质" << "(" << player.defence << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  e.灵巧" << "(" << player.Dexterity << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  f.金钱" << "(" << player.money << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  g.名声" << "(" << player.fame << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  h.魅力" << "(" << player.charm << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  i.游戏累计时间" << "(" << player.time << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  j.移动速度" << "(" << int(player.move_speed) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  k.攻击速度" << "(" << int(player.attack_speed) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  l.攻击范围" << "(" << int(player.attack_range) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  m.攻击力" << "(" << player.attack_power << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  n.防御力" << "(" << player.defence_power << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  o.敏捷度" << "(" << int(player.agility) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  p.智力" << "(" << int(player.intelligence) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  q.经验" << "(" << int(player.experience) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  r.等级" << "(" << int(player.level) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  s.魔法值" << "(" << player.magicPoints << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  t.消耗魔法值" << "(" << int(player.magicCost) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  u.魔法伤害力" << "(" << int(player.magicDamage) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  v.魔法命中率" << "(" << int(player.hitRate) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  w.魔法防御力" << "(" << int(player.magicDefense) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  x.暴击率" << "(" << int(player.criticalHitRate) << ")" << endl;
    cout << setw(16) << setiosflags(ios::left) << "  y.耐力" << "(" << int(player.stamina) << ")" << endl;
    cout << "--------------------------------------" << endl;
    cout << "  0.放弃修改" << endl;
    cout << "  1.存盘退出" << endl;
    cout << "--------------------------------------" << endl;
    cout << "请选择[a..y, 0..1] ";
}

template<typename T>
void judge_modify(T& value, int min ,int max,const char* const prompt)
{  
    if (typeid(T) == typeid(long long)) {
        while (1) {
            long long temp;
            cout << prompt << "，当前值=" << static_cast<long long>(value) << ", 范围[" << static_cast<long long>(min) << ".." << static_cast<long long>(max) << "]" << "，请输入 : ";
            cin >> temp;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(65536, '\n');
            }
            else {
                if (temp < min || temp > max) {
                    cout << "非法的" << prompt << "值：" << temp << endl;
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
            cout << prompt << "，当前值=" << static_cast<int>(value) << ", 范围[" << static_cast<int>(min) << ".." << static_cast<int>(max) << "]" << "，请输入 : ";
            cin >> temp;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(65536, '\n');
            }
            else {
                if (temp < min || temp > max) {
                    cout << "非法的" << prompt << "值：" << temp << endl;
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
            choice = choice - 'A' + 'a';//转换为小写
        }
        switch (choice) {
            case 'a':
                cout << "玩家昵称" << "，当前值=" << player.name << "，请输入 : " ;
                char temp[16];
                cin >> temp;
                temp[15] = '\0';
                strncpy(player.name, temp, 16);
                cin.clear();
                cin.ignore(65536, '\n');
                break;
            case 'b':
                judge_modify(player.hp, 0, 10000, "生命");
                break;
            case 'c':
                judge_modify(player.power, 0, 10000, "力量");
                break;
            case 'd':
                judge_modify(player.defence, 0, 8192, "体质");
                break;
            case 'e':
                judge_modify(player.Dexterity, 0, 1024, "灵巧");
                break;
            case 'f':
                judge_modify(player.money, 0, 10000000, "金钱");
                break;
            case 'g':
                judge_modify(player.fame, 0, 1000000, "名声");
                break;
            case 'h':
                judge_modify(player.charm, 0, 1000000, "魅力");
                break;
            case 'i':
                judge_modify(player.time, 0, 10000000 ,"游戏累计时间");
                break;
            case 'j':
                judge_modify(player.move_speed, 0, 100, "移动速度");
                break;
            case 'k':
                judge_modify(player.attack_speed, 0, 100, "攻击速度");
                break;
            case 'l':
                judge_modify(player.attack_range, 0, 100, "攻击范围");
                break;
            case'm':
                judge_modify(player.attack_power, 0, 2000, "攻击力");
                break;
            case 'n':
                judge_modify(player.defence_power, 0, 2000, "防御力");
                break;
            case 'o':
                judge_modify(player.agility, 0, 100, "敏捷度");
                break;
            case 'p':
                judge_modify(player.intelligence, 0, 100, "智力");
                break;
            case 'q':
                judge_modify(player.experience, 0, 100, "经验");
                break;
            case 'r':
                judge_modify(player.level, 0, 100, "等级");
                break;
            case's':
                judge_modify(player.magicPoints, 0, 10000, "魔法");
                break;
            case 't':
                judge_modify(player.magicCost, 0, 100, "消耗魔法");
                break;
            case 'u':
                judge_modify(player.magicDamage, 0, 100, "魔法伤害力");
                break;
            case 'v':
                judge_modify(player.hitRate, 0, 100, "命中率");
                break;
            case 'w':
                judge_modify(player.magicDefense, 0, 100, "魔法防御力");
                break;
            case 'x':
                judge_modify(player.criticalHitRate, 0, 100, "暴击率");
                break;
            case 'y':
                judge_modify(player.stamina, 0, 100, "耐力");
                break;
            case '0':
                loop = false;//退出修改
                break;
            case '1':
                loop = false;//退出修改并存盘
                save = true;//标记存盘
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
  说    明：整个函数，只允许出现一次open、一次read（因为包含错误处理，允许多次close）
***************************************************************************/
int read(struct demo& player)
{
    /* 本函数中只允许定义一个 ifstream流对象，不再允许定义任何形式的fstream/ifstream/ofstream流对象，也不允许使用C方式的文件处理 */
    ifstream gfile;

    /* 文件打开，具体要求为：
       1、要求以读方式打开，打开方式***自行指定
       2、除本次open外，本函数其它地方不允许再出现open  */
    gfile.open("game.dat", ios::binary);
    if (!gfile) {
        cout << "无法打开文件game.dat" << endl;
        return 1;
    }
    if (gfile.seekg(0, ios::end).tellg() != 64) {
        cout << "文件game.dat的字节大小不正确" << endl;
        gfile.close();
        return 1;
    }
    gfile.seekg(0, ios::beg);
    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 gfile.read(***, sizeof(demo));
    */
    gfile.read((char*)&player, sizeof(demo));
    gfile.close();
    print_demo(player);
    return 0;

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read、一次write（因为包含错误处理，允许多次close）
***************************************************************************/
int modify(struct demo& player)
{
    /* 本函数中只允许定义一个 fstream流对象，不再允许定义任何形式的fstream/ifstream/ofstream流对象，也不允许使用C方式的文件处理 */
    fstream gfile;

    /* 文件打开，具体要求为：
       1、要求以读写方式打开，打开方式***自行指定
       2、除本次open外，本函数其它地方不允许再出现open  */
    gfile.open("game.dat", ios::in | ios::out | ios::binary);
    if (!gfile) {
        cout << "无法打开文件game.dat" << endl;
        return 1;
    }
    if (gfile.seekg(0, ios::end).tellg() < 64) {
        cout << "文件game.dat的字节大小不正确" << endl;
        gfile.close();
        return 1;
    }
    gfile.seekp(0, ios::beg);
    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 gfile.read(***, sizeof(demo));
             只允许用一次性写入64字节的方法将***的内容写入game.dat中（缓冲区名称、结构体名称自行指定）
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数允许带参数，不允许进行文件读写
***************************************************************************/
int main(int argc, char** argv)
{
   struct demo player;
   /*cout<<sizeof(player)<<endl;*/
   if (argc == 2) { /* 进行参数处理，如读取参数值、修改游戏数据等 */
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