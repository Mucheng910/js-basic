#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 30
#define INFINITY 9999 
#define MAX 15 // ���κ� 
//������Ϣ
typedef struct {
	int NO;//������� 
	char name[20];//�������� 
}CityNode;
//·����Ϣ 
typedef struct {
	int money;//��λ��Ԫ
	char number[MAX];//���κ� 
	CityNode startCity;//��ʼ����
	CityNode endCity;//�������
	int StartTime;//��ʼʱ�䵥λ����
	int EndTime;//����ʱ�䵥λ����
	int CostTime;//����ʱ�䵥λ���� 
}ArcsNode,*ArcsPtr;
//ͼ����Ϣ 
typedef struct {
	ArcsNode Edg[MAXSIZE];
    int arcs[MAXSIZE][MAXSIZE];//�ߵļ��ϣ�1��ʾ��·����0��ʾû��·�� 
	int vexnum;//����ĸ��� 
	int arcsnum; //�ߵĸ��� 
}AdjMatrix; 

void First(AdjMatrix *G);
void Creat(AdjMatrix *G);
void Query(AdjMatrix G);
void First(AdjMatrix *G){
	int logo;
	printf("��ѡ����Ҫִ�еĲ�����\n��·�߽���->1��ɾ�����޸ģ�2����ѯ\n");
	scanf("%d",&logo);
	switch(logo){
		case 1:Creat(G);break;
		case 2:Query(*G);break;
	    default:printf("��������ȷ����ʾ��Ϣ��"); 
	} 
}
void Creat(AdjMatrix *G){
	int i,j;
	CityNode city;
	FILE *fp;//ָ�������Ϣ���ļ�ָ�� 
	FILE *fs;//ָ��ʱ�̱���ļ�ָ�� 
	printf("��������и�����·�ߵĸ�����\n");
	scanf("%d%d",&G->vexnum,&G->arcsnum);
    fp = fopen("������Ϣ.txt","w");
    printf("����������Ϊ0000��ʾ������\n");
	for(i=0;i<G->vexnum;i++){ 
	   printf("NO.",i+1);
	   scanf("%d",&city.NO);
	   if (city.NO!=0000){
		  scanf("%s",city.name); 
		  fwrite(&city,sizeof(CityNode),1,fp);
       }
       else
        printf("��Ϣ���³ɹ���");
    fclose(fp); 
    }
}
//void Query(AdjMatrix G){
//	int logo,start,end;
//	printf("��������Ҫ��ѯ��·����ʼ���к�Ҫ����ĳ��е���ţ�\n");
//	//���ļ��ڳ��е����
//	scanf("%d%d",&start,&end);
//	printf("ѡ��һ����ľ���,1:��쵽�2���������٣�3����תվ���٣�\n");      	
//	scanf("%d",&logo);
//}
int main() {
	AdjMatrix G;
	First(&G); 
	return 0;
}
