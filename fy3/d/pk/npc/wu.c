inherit NPC;

string ask_me();

void create()
{
        set_name("����ʹ��", ({ "bisai shizhe", "shizhe","bisai" }));
        set("gender", "����");
        set("age", 47);

        set("inquiry", ([
"ɱ�˱���": "��Ҳ��μӣ���answer��\n",
"ɱ��": "��Ҳ��μӣ���answer��\n",
"����": "��Ҳ��μӣ���answer��\n",
        ]) );
 
        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        add_action("do_sign", "answer");
}
int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
        message_vision("$n��$N�������ã��ҿ����㹻�����ʸ񡣡�\n",
                       me, this_object());
                if (me->query("pkover") > 1)
        {
                message_vision("$ņͷ���˿�$N����м�������Ѿ��μӹ���,����ɣ�\n",
                               me, this_object());
                return 1;
        }
                if (me->query("combat_exp") < 1000000)
        {
                message_vision("$ņͷ���˿�$N����м����������"
                               "��㱾�£�ֻ�òμӱ�ɱ��������\n",
                               me, this_object());
                return 1;
        }
                if (me->query("sxwuqi" ) == 1)
        {
                message_vision("$ņͷ���˿�$N����м�����㲻֪�������Դ������\n",me, this_object());
                return 1;
        }

        message_vision("$n���ͷ����$N�������ðɣ����Ƚ�"
                       "ȥ׼���ɡ���\n$N���ͷ�������"
                       "׼������ȥ��\n", me, this_object());
        me->move("/d/pk/ready");
              me->set("pkover",1);        
message("vision", me->name() + "�����ӵ����˽�����\n",
                environment(me), ({ me }));
        return 1;
}
