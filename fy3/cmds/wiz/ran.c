int help(object me);

int main(object me, string arg)
{
        int t;
        int i,j;
        int *a;
        int temp;
        if (!arg || sscanf(arg,"%d",t)!=1)
                return help(me);
       call_out("main_b",10);
        a = allocate(10);
        for (j=0;j<10;j++)
                a[j]=0;
        for (i=0;i<1000;i++) {
                temp=random(t);
//             printf("random(%d) is : %d\n",t,temp);
                for (j=0;j<10;j++) {
                        if (temp < (t/10)*(j+1)) {
                                a[j]=a[j]+1;
                                break;
                        }
                }

        }
        for (j=0;j<10;j++)
                printf("%d : ����Ϊ %d\n",j,a[j]);
        return 1;
}

void main_b()
{
    write("ok!\n");
}
int help(object me)
{
write(@HELP
ָ���ʽ : ran <number>

�ô� : ������������ķֲ���
HELP
     );
     return 1;
}

