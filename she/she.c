#include<stdio.h>//������
#include<stdlib.h>//ϵͳ��
#include<windows.h>//��궨λ���ַ���ɫ������
#include<time.h>//ʱ�亯����
#include<conio.h>//��ֵ���뺯����
#include<stdbool.h>
#define width 60
#define height 25
struct ssnake
{
int f;//������Ч��־
int x;
int y;//��������
};
void color(int b) //��ɫ����
{
HANDLE hConsole = GetStdHandle((STD_OUTPUT_HANDLE)) ;
SetConsoleTextAttribute(hConsole,b) ;
}
void HideCursor()//���ع��
{
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursor_info={1,0};
SetConsoleCursorInfo(hOut,&cursor_info);
}

void gotoxy(int x,int y)//�����ַ���ʾλ��
{
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD loc={x,y};
SetConsoleCursorPosition(hOut,loc);
}
void drawmap(char *mp,char *omp,struct ssnake *snp)
{//������
char pel[]="����";
int i,j,k;
for(i=0;snp[i].f>0;i++)
{
j=4;//����
if(i==0)j=2;//��ͷ
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
{//����ƻ�����λ��
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
char map[width][height]={0},oldmap[width][height]={0};//���� 0:�� 2:��ͷ 4:���� 6:ƻ��
int mx=0,my=0;//��ͷ�ƶ�����
int apx=-1,apy=-1;//ƻ��λ��
int i,j,sc=0,ef=0,sp=210;
long t1,nt;//��ʱ
char a;
bool pf=false;//��ͣ��־
struct ssnake sn[1500]={0};//�ߣ��1500���ؽڣ��ؽ����ݽṹΪssnake��
nt=clock();
t1=nt;
system("mode con cols=80 lines=25");
HideCursor();
for(i=0;i<height;i++){gotoxy(width,i);printf("��");}
color(14);
gotoxy(width+4,12);printf("����:��������");
gotoxy(width+4,14);printf("�ո�:��ͣ");
gotoxy(width+4,16);printf("ESC :�˳�");
gotoxy(width+4,18);printf("�÷�:%d",sc);
sn[0].f=1;sn[0].x=30;sn[0].y=10;sn[1].f=0;//��ͷλ��
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
if(a=='M'&&mx!=-2){mx=2;my=0;}//�����ƶ��������ú��ַ��ű�ʾ�����Բ���Ϊ2
if(a=='H'&&my!=1){my=-1;mx=0;}
if(a=='P'&&my!=-1){my=1;mx=0;}//�����ƶ�
}
else
{
if(a==27){ef=1;break;}//��Ϊ�˳�
if(a==32)pf=!pf;
}
}
if(!pf&&nt-t1>sp)
{
t1=nt;
for(i=0;sn[i].f>0;i++);
for(j=i;j>0;j--){sn[j].x=sn[j-1].x;sn[j].y=sn[j-1].y;}//����ǰ��
if(sn[i+1].f=0){gotoxy(sn[i].x,sn[i].y);printf(" ");}
sn[0].x+=mx;sn[0].y+=my;//��ͷǰ��
if(sn[0].x<0||sn[0].x>=width||sn[0].y<0||sn[0].y>=height){ef=2;break;}//Խ��
for(j=1;sn[j].f>0;j++){if(sn[j].x==sn[0].x&&sn[j].y==sn[0].y)break;}
if(sn[j].f!=0){ef=3;break;}//�ж��Ƿ��Լ����Լ�
if(sn[0].x==apx&&sn[0].y==apy)//����ƻ��
{
sn[i].f=1;sn[i+1].f=0;apx=-1;apy=-1;sp--;
sc=sc+10+i;//�ɼ��ۼ�
gotoxy(64,18);printf("�÷�:%d",sc);
}
}
for(i=0;i<width;i++)
for(j=0;j<height;j++)
map[i][j]=0;
if(apx<0&&apy<0)rndapple(sn,&apx,&apy);//��ȡƻ��λ��
if(apx>=0&&apy>=0)
map[apx][apy]=6;//����ƻ��
else
{//�Ѿ�û�п�λ��ƻ��λ���ˣ�˵�����㹻�������ǲ����ܵ�
gotoxy(62,24);
printf("���������֣�");
break;
}
drawmap(&map[0][0],&oldmap[0][0],sn);
}
gotoxy(25,23);
color(15);
if(ef==1)printf("�˳���Game Over!\n");
if(ef==2)printf(" Խ��!Game Over!\n");
if(ef==3)printf("��ɱ�ˣ�Game Over!\n");
}
