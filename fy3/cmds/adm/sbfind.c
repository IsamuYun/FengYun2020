//Heart of fy3 -- sbaa
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8
inherit  TASK_D;
string locate_obj1(object me,string str);

int main(object me, string str)
{
	string output = "";
        if(!str) return notify_fail("ָ���ʽ: sbfind <��Ʒ>\n");
	//me->add("sen",-5);
	output = locate_obj1(me,str);
	if(output=="")
		return notify_fail("ȷ������"+str+"�Ĵ��λ�á�\n");
	write(output);
	return 1;
}

string locate_obj1(object me,string strr)
{
        string *distance = ({
"����", "�ܽ�", "�ȽϽ�", "��Զ",
"����", "�Ƚ�Զ", "��Զ", "��Զ"
        });
        string *altitude =({
"�ߴ�", "�ط�", "�ʹ�"
        });
        string *directions=({
"��Χ","����", "�Ϸ�", "����","����",
"������","������","���Ϸ�","���Ϸ�"
        });
        object ob, tmpobj,where, *ob_list;
        object item,room,room2;
        string output,dis,alt,dir;
        int i;
        int x,y,z,x0,y0,z0;
        int realdis;
        int tmp;
	string str="";
	reset_eval_cost();
        for( i=0; i < sizeof(quests); i++)
	{
        if(!objectp(item= find_object(quests[i]["file_name"])))
        item = load_object(quests[i]["file_name"]);
	if(item->query("id") == strr || item->query("name") == strr) str = quests[i]["file_name"];
	}
	if(str != "") {
                room = environment(me);                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                {
                        x0= (int)room->query("coor/x");
                        y0= (int)room->query("coor/y");
                        z0= (int)room->query("coor/z");
                        x=(int)ob->query("coor/x")-x0;
                        y=(int)ob->query("coor/y")-y0;
                        z=(int)ob->query("coor/z")-z0;
                        realdis=0;
                        if(x<0)realdis-=x; else realdis+=x;
                        if(y<0)realdis-=y; else realdis+=y;
                        if(z<0)realdis-=z; else realdis+=z;
                        tmp =(int)  realdis/50;
                        if(tmp>MAX_DIS) tmp = MAX_DIS;
                        dis=distance[tmp];
                        if(z>0) alt=altitude[0];
                        if(z<0) alt=altitude[2];
                        if(z==0) alt=altitude[1];
                        if(x==0&&y==0) dir=directions[0];
                        if(x==0&&y>0) dir=directions[1];
                        if(x==0&&y<0) dir=directions[2];
                        if(x>0&&y==0) dir=directions[3];
                        if(x<0&&y==0) dir=directions[4];
                        if(x>0&&y>0) dir=directions[5];
                        if(x<0&&y>0) dir=directions[6];
                        if(x>0&&y<0) dir=directions[7];
                        if(x<0&&y<0) dir=directions[8];
room2 = ob;

        output = "��"+ob_list[i]->query("name")+"���ƺ���"+dir+dis+"��"+alt+room2->query("short")+(string)file_name(room2)+"��\n";
	return output;
                }
                }
	}
	else 
	if(wizardp(me) || me->query("class") == "official")
	{
        tmpobj = find_player(strr);
        if(!tmpobj) tmpobj = find_living(strr);
        if(!tmpobj) return "";
	ob = find_env(tmpobj);
	room = environment(me);
	if(ob)
	{
                        x0= (int)room->query("coor/x");
                        y0= (int)room->query("coor/y");
                        z0= (int)room->query("coor/z");
                        x=(int)ob->query("coor/x")-x0;
                        y=(int)ob->query("coor/y")-y0;
                        z=(int)ob->query("coor/z")-z0;
                        realdis=0;
                        if(x<0)realdis-=x; else realdis+=x;
                        if(y<0)realdis-=y; else realdis+=y;
                        if(z<0)realdis-=z; else realdis+=z;
                        tmp =(int)  realdis/50;
                        if(tmp>MAX_DIS) tmp = MAX_DIS;
                        dis=distance[tmp];
                        if(z>0) alt=altitude[0];
                        if(z<0) alt=altitude[2];
                        if(z==0) alt=altitude[1];
                        if(x==0&&y==0) dir=directions[0];
                        if(x==0&&y>0) dir=directions[1];
                        if(x==0&&y<0) dir=directions[2];
                        if(x>0&&y==0) dir=directions[3];
                        if(x<0&&y==0) dir=directions[4];
                        if(x>0&&y>0) dir=directions[5];
                        if(x<0&&y>0) dir=directions[6];
                        if(x>0&&y<0) dir=directions[7];
                        if(x<0&&y<0) dir=directions[8];
room2 = ob;

output = "��"+ob_list[i]->query("name")+"���ƺ���"+dir+dis+"��"+alt+room2->query("short")+(string)file_name(room2)+"��\n";        
//output = "��"+tmpobj->query("name")+"���ƺ���"+dir+dis+"��"+alt+"��\n";
        return output;
	}
        }
                return "";

}

