#include<stdio.h>

int main() {

    char p[10][5];

    int tot=0,wt[10], pt[10], i,n;

    double avg=0;

    printf("Enter # of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Enter Process %d Name : ",i+1);
        scanf("%s",&p[i][0]);
        printf("Enter Process Time : ");
        scanf("%d",&pt[i]);
    }

    wt[0]=0;

    for(i=1;i<n;i++) {
        wt[i]=wt[i-1]+pt[i-1];
        tot=tot+wt[i];
    }

    avg=(double)tot/n;

    printf("P_Name\tP_Time\tW_Time\n");

    for(i=0;i<n;i++)
        printf("%s\t%d\t%d\n",p[i],pt[i],wt[i]);

    printf("Total Waiting Time = %d\nAvgerage Waiting Time = %lf\n",tot,avg);

}