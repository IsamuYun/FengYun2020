inherit NPC;

string ask_me();

void create()
{
        set_name("����ʹ��", ({ "bisai shizhe", "shizhe","bisai" }));
        set("gender", "����");
        set("age", 47);

        set("inquiry", ([
"׼��": "��׼�������𣿿�ʼ����?��gone��\n",
"����": "��׼�������𣿿�ʼ����?��gone��\n",
"��ʼ": "��׼�������𣿿�ʼ����?��gone��\n",
        ]) );
 
        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        add_action("do_sign", "gone");
}
int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
              ob = new("/d/pk/obj/ling");
           if(me->query_temp("pkok") == 1)
                  return notify_fail("�������Ѿ���ɱ��֤�˻�����\n");
       message_vision("$n��$N�������ã���ͽ�ȥ�ɣ�ף����ˡ���\n",
                       me, this_object());
             ob->set("srname",me->query("id"));
        ob->move(me);
         me->set_temp("pkok",1);        
        return 1;
}
