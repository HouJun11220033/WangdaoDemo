//����+��֦����ż��֦��
#include<stdio.h>
#include<stdlib.h>
using namespace std;
char maze[8][8];
int n,m,t;
bool success;
int go[4][2]={
	1,0,
	-1,0,
	0,1,
	0,-1,
};
void DFS(int x,int y,int time)
{
	for (int i = 0;i < 4;i ++) { //ö���ĸ�����λ��
	int nx = x + go[i][0];
	int ny = y + go[i][1]; //����������
	//!!!!!!����forѭ������Ķ���������ҲҪ�ǵøģ�������
	if (nx < 0 || nx > n || ny < 0 || ny > m) continue; //�������ڵ�ͼ������

	if (maze[nx][ny] == 'X') continue; //����λ��Ϊǽ,����
	if (maze[nx][ny] == 'D') {				 //����λ��Ϊ��
		if (time + 1== t) {	//������ʱ��ǡ��Ϊt
		success = true; //�����ɹ�
		return; //����
	}
	else continue; //�����״̬�ĺ���״̬������Ϊ��(�����ĵ㲻���پ���),��
			
	}
	maze[nx][ny] = 'X'; //��״̬��չ�����ĺ���״̬��,��λ�ö����ܱ�����,ֱ���޸�λ��Ϊǽ

	DFS(nx,ny,time + 1); //�ݹ���չ��״̬,����ʱ�����
	maze[nx][ny] = '.'; //�������״̬ȫ���������,���˻��ϲ�״̬,����ΪҪ��������״̬���ĳ�ǽ��λ��,�Ļ���ͨλ��

	if (success) return;//�����Ѿ��ɹ�,��ֱ�ӷ���,ֹͣ����
	}
}
int main(){
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		if(n==0 && m==0 && t==0)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
		}
		success=false;
		int sx,sy;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='D')
				{
					sx=i;
					sy=j;
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			for (int j = 0;j < m;j ++)
			{
				//��֦
				if(maze[i][j] == 'S' && (i + j) % 2 ==  ( (sx + sy) % 2 + t %2 ) % 2) 

				{
					maze[i][j]='X';
					DFS(i,j,0);
				}
				
			}
		}
		puts(success==true ?"YES":"NO");
		system("pause");
	}
	return 0;
}