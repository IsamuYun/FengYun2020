inherit ITEM;
int smoking(int);
void create()
{
        string *order = ({"�л�����","婺�����","����ɽ����", "��·����", "�Ͼ�����","��â��","ܽ����"});
        set_name( (order[random(7)]), ({ "cigarette" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����̣�����(xiyan)��\n");
                set("unit", "��");
                set("count",6);
                set("value", 500);
        }
}

void init()
{
        add_action("do_smoke", "xiyan");
}

int do_smoke()
{
        object me = this_player();
        object obj = this_object();
        if(query("count") == 6) 
                message_vision("$N���һ֧$n�������˻������̵�����������\n", me, this_object());
        else if (query("count") == 1 ) {
                message_vision("$N������һ��ʣ�µ���ƨ�ɣ������ֲ�����������ȥģ�ڴ���\n", me);
                destruct(this_object());
                return notify_fail("");
        } else 
        switch(random(4)) {
          case 0: message_vision("$N�³�һ����Ȧ�����������е�ɢ����\n", me);
                        break;
          case 1: message_vision("$N�ݺݵ�����һ��$n�����������̫���ˣ�һ�����ǵ�ͨ�졣\n", me, obj);
                        break;
          case 2: message_vision("$N����һ��$n��ҡͷ���Ե�˵����������һ֧�̣����������ɡ���\n", me, obj );
                        break;
          case 3: message_vision("$N��������ȣ�������һ��$n�����Ե������ⶫ�������ֺ�����Ϊɶ�һ���ôϲ������\n", me, obj);
                        break;
                default:
                        break;
        }
        add("count",-1);
        return notify_fail("");
}
