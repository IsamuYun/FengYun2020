//�������������ͳһ��40����һ��
//�÷���վ�ڷ����������������Ϳ�����
//ÿ��40���������Ժ󣬼����һ�е�ͷһ�����ǲ��Ǳ�����,�����,�ͽ��ñ�����
//�ӵ���ǰ��һ�С������ſ�����is_punctuation��������

#include <ansi.h>
inherit F_CLEAN_UP;

string change_room_long(string roomlong,string file);
int is_punctuation(string str);
int main(object me, string arg)
{
        int i,j,hang,x,y,z,aa,last,a,b,c,d;//���б��
        string stt,mmssgg,file,ab;
        string str,roomlong1,roomlong2,roomlong3,file_str;
	object env;	
        
        env=environment(me);
	
	ab=",";
	if(is_punctuation(ab))
	tell_object(me,ab+"yes\n");
	//return 1;
	roomlong1=env->query("long");
	roomlong1=replace_string(roomlong1,"\n","");
	roomlong1=replace_string(roomlong1,"\t","");
	roomlong1=replace_string(roomlong1," ","");
	roomlong2="";
	x=0;y=0;i=sizeof(roomlong1);
	hang=i/56;
	z=0;
	z=i%56;
	if(z!=0) hang++;
	
	last=0;
	roomlong2="\n"+roomlong2;
	for(x=0;x<hang;x++)
	{
		aa=0;
		if(last>i-1) break;//��ֹlast�����ַ���Χ
		if(hang-x==1)//���һ�� 
		{
			roomlong2=roomlong2+"\""+roomlong1[last..i-1]+"\\n"+"\""+"\n";
			break;
		}
		else{

			for(j=0;j<56;j++)
			{
				if(last+j>i-1) break;
				if(roomlong1[last+j]<=160)//����������
					aa++;
				else continue;
			}
			if(aa%2!=0) //��һ���м�����������,Ҫ�����⴦��,�е�������ּ�1.
			{

				roomlong2=roomlong2+"\""+roomlong1[last..last+54];//��һ�е����������һ
				last=last+55;
				if( (i-1)-last>=1 )//��һ�����ٻ���2���ַ���λ��,�ж�����һ�еĿ�ͷ�ǲ��Ǳ�����
				{
				
					if(is_punctuation(roomlong1[last..last+1])!=-1)//�ж��Ƿ����ı�����
					{
				
				
						roomlong2=roomlong2+roomlong1[last..last+1]+"\\n"+"\""+"\n";
						last+=2;
						continue;
					}
					if(is_punctuation(roomlong1[last..last])!=-1)//Ӣ�ı�����
					{
				
						roomlong2=roomlong2+roomlong1[last..last]+"\\n"+"\""+"\n";
						last++;
						continue;
					}
					roomlong2=roomlong2+"\\n"+"\""+"\n";
					continue;
				}
				else if( (i-1)-last>=0)//��һ�����ٻ���һ���ַ���λ��,�ж����Ŀ�ͷ�ǲ���Ӣ�ı��
				{
					if(  is_punctuation(roomlong1[last..last])!=-1  )
					{
				
						roomlong2=roomlong2+roomlong1[last..last]+"\\n"+"\""+"\n";
						last++;
						continue;
					}
					roomlong2=roomlong2+"\\n"+"\""+"\n";
					continue;	
				}
				//roomlong2=roomlong2+"\\n"+"\""+"\n";
				
			}
			else//��һ��40��ȫ����������
			{
				//write_file("/open/rongg/hang.txt",roomlong1[last..last+79]+"\n",0);
				roomlong2=roomlong2+"\""+roomlong1[last..last+55];
				last=last+56;
				//write("last is\t"+last+"\t roomlong1[last..last]     is \t"+roomlong1[last..last]+"\n");
				if( (i-1)-last>=1 )//��һ�����ٻ���2���ַ���λ��,�ж�����һ�еĿ�ͷ�ǲ��Ǳ�����
				{
					if(is_punctuation(roomlong1[last..last+1])!=-1)//���ı�����
					{  
						write("roomlong1[last..last+1]     is     \t"+roomlong1[last..last+1]+"\n");
						roomlong2=roomlong2+roomlong1[last..last+1]+"\\n"+"\""+"\n";
						last+=2;
						continue;
					}
					if(is_punctuation(roomlong1[last..last])!=-1)//Ӣ�ı�����
					{
						write("\t roomlong1[last..last] is \t"+roomlong1[last..last]+"\n");
						roomlong2=roomlong2+roomlong1[last..last]+"\\n"+"\""+"\n";
						last++;
						continue;
					}
					roomlong2=roomlong2+"\\n"+"\""+"\n";
					continue;	
				}
				else if( (i-1)-last>=0)//��һ�����ٻ���һ���ַ���λ��,�ж����Ŀ�ͷ�ǲ���Ӣ�ı��
				{
					if(  is_punctuation(roomlong1[last..last])!=-1  )
					{
						roomlong2=roomlong2+roomlong1[last..last]+"\\n"+"\""+"\n";
						last++;
						continue;
					}
					roomlong2=roomlong2+"\\n"+"\""+"\n";
					continue;	
				}
				roomlong2=roomlong2+"\\n"+"\""+"\n";
				
			}

		}
	}
	//write_file("/open/rongg/hang.txt",roomlong2,0);
	file=base_name(env);
	file+=".c";
	file_str=change_room_long(roomlong2,file);
   	write_file(file,file_str,1);
   	"/cmds/wiz/update"->main(me,"here");
   	return 1;
}

string change_room_long(string roomlong,string file)
{
	

        string file_str,all,head,str1;
        int i,j,k,l,m;
	//file+=".c";
        roomlong="set(\"long\","+roomlong+");";
        if(!stringp(str1=read_file(file,0))) {
		return 0;
	}
	all=str1;//�����ļ�
	i=strsrch(str1,"create(");//����create�ҵ�
	j=strsrch(str1[i..],"set(\"long\",");//set("long",)������ʼ���ҵ�
	if(i<0||j<0) return 0;
	k=strsrch(str1[i+j..],");");//�����������ҵ�
	if(k<0) return 0;
	file_str=all[0..i+j-1]+roomlong+all[i+j+k+2..];
	return file_str;
}





int is_punctuation(string str)
{
	string *punctuation;
	punctuation=({
		",",
		".",
		"?",
		";",
		":",
		"!",
		")",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��",
		});
	if(!str) return -1;
        return member_array(str,punctuation);
}