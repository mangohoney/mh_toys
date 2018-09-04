#include<stdio.h>//基本库
#include<stdlib.h>//系统库
#include<windows.h>//光标定位、字符颜色函数库
#include<time.h>//时间函数库
#include<conio.h>//键值读入函数库
#include<stdbool.h>
#define width 60
#define height 25
struct ssnake
{
int f;//蛇身有效标志
int x;
int y;//蛇身坐标
};
void color(int b) //颜色函数
{
HANDLE hConsole = GetStdHandle((STD_OUTPUT_HANDLE)) ;
SetConsoleTextAttribute(hConsole,b) ;
}
void HideCursor()//隐藏光标
{
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursor_info={1,0};
SetConsoleCursorInfo(hOut,&cursor_info);
}

void gotoxy(int x,int y)//设置字符显示位置
{
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD loc={x,y};
SetConsoleCursorPosition(hOut,loc);
}
void drawmap(char *mp,char *omp,struct ssnake *snp)
{//画场景
char pel[]="■●";
int i,j,k;
for(i=0;snp[i].f>0;i++)
{
j=4;//蛇身
if(i==0)j=2;//蛇头
mp[snp[i].x*height+snp[i].y]=j;
}
for(k=0;k<width*height;k++)
{
if(mp[k]!=omp[k])
{
i=k/height;j=k%height;
color(15);
if(mp[k]==6)color(13);
omp[k]=mp[k];
gotoxy(i,j);
printf("%c",pel[mp[k]]);
printf("%c",pel[mp[k]+1]);
}
}
}
void rndapple(struct ssnake *snp,int *px,int *py)
{//产生苹果随机位置
bool f=false;
int i,j,k=0,z[1500][2]={0};
char map[width][height]={0};
*px=-1;*py=-1;
for(i=0;snp[i].f>0;i++)map[snp[i].x][snp[i].y]=1;
for(i=0;i<width;i+=2)
for(j=0;j<height;j++)
{
if(map[i][j]==0)
{
z[k][0]=i;
z[k][1]=j;
k++;
}
}
if(k>0)
{
i=rand()%k;
*px=z[i][0];
*py=z[i][1];
}
}

int main(void)
{
char map[width][height]={0},oldmap[width][height]={0};//场景 0:空 2:蛇头 4:蛇身 6:苹果
int mx=0,my=0;//蛇头移动方向
int apx=-1,apy=-1;//苹果位置
int i,j,sc=0,ef=0,sp=210;
long t1,nt;//计时
char a;
bool pf=false;//暂停标志
struct ssnake sn[1500]={0};//蛇，最长1500个关节，关节数据结构为ssnake，
nt=clock();
t1=nt;
system("mode con cols=80 lines=25");
HideCursor();
for(i=0;i<height;i++){gotoxy(width,i);printf("‖");}
color(14);
gotoxy(width+4,12);printf("控制:←↑→↓");
gotoxy(width+4,14);printf("空格:暂停");
gotoxy(width+4,16);printf("ESC :退出");
gotoxy(width+4,18);printf("得分:%d",sc);
sn[0].f=1;sn[0].x=30;sn[0].y=10;sn[1].f=0;//蛇头位置
srand((unsigned)time(NULL));
while(1)
{
nt=clock();
if(kbhit())
{
a=getch();
if(a<0)
{
a=getch();
if(a=='K'&&mx!=2){mx=-2;my=0;}
if(a=='M'&&mx!=-2){mx=2;my=0;}//左右移动，由于用汉字符号表示，所以步长为2
if(a=='H'&&my!=1){my=-1;mx=0;}
if(a=='P'&&my!=-1){my=1;mx=0;}//上下移动
}
else
{
if(a==27){ef=1;break;}//人为退出
if(a==32)pf=!pf;
}
}
if(!pf&&nt-t1>sp)
{
t1=nt;
for(i=0;sn[i].f>0;i++);
for(j=i;j>0;j--){sn[j].x=sn[j-1].x;sn[j].y=sn[j-1].y;}//蛇身前进
if(sn[i+1].f=0){gotoxy(sn[i].x,sn[i].y);printf(" ");}
sn[0].x+=mx;sn[0].y+=my;//蛇头前进
if(sn[0].x<0||sn[0].x>=width||sn[0].y<0||sn[0].y>=height){ef=2;break;}//越界
for(j=1;sn[j].f>0;j++){if(sn[j].x==sn[0].x&&sn[j].y==sn[0].y)break;}
if(sn[j].f!=0){ef=3;break;}//判断是否自己吃自己
if(sn[0].x==apx&&sn[0].y==apy)//吃了苹果
{
sn[i].f=1;sn[i+1].f=0;apx=-1;apy=-1;sp--;
sc=sc+10+i;//成绩累加
gotoxy(64,18);printf("得分:%d",sc);
}
}
for(i=0;i<width;i++)
for(j=0;j<height;j++)
map[i][j]=0;
if(apx<0&&apy<0)rndapple(sn,&apx,&apy);//获取苹果位置
if(apx>=0&&apy>=0)
map[apx][apy]=6;//设置苹果
else
{//已经没有空位画苹果位置了，说明蛇足够长，这是不可能的
gotoxy(62,24);
printf("厉害，满分！");
break;
}
drawmap(&map[0][0],&oldmap[0][0],sn);
}
gotoxy(25,23);
color(15);
if(ef==1)printf("退出！Game Over!\n");
if(ef==2)printf(" 越界!Game Over!\n");
if(ef==3)printf("自杀了！Game Over!\n");
}
