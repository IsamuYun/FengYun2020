inherit NPC;

string ask_me();

void create()
{
        set_name("����ʹ��", ({ "bisai shizhe", "shizhe","bisai" }));
        set("gender", "����");
        set("title", "����ɱ�˴���");
        set("age", 47);

        set("inquiry", ([
"ɱ�˱���": "��Ҳ��μӣ�\n��answer���Ϳ�����,���������ϵ����ж�����û�ա�\n",
"����": "��Ҳ��μӣ�\n��answer���Ϳ�����,���������ϵ����ж�����û�ա�\n",
"ɱ��": "��Ҳ��μӣ�\n��answer���Ϳ�����,���������ϵ����ж�����û�ա�\n",
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
        int i;
        object *inv;
        object me;
        string msg;
        object ob;

        me = this_player();
        message_vision("$n��$N�������ã��ҿ����㹻�����ʸ񡣡�\n",
                       me, this_object());
                if (me->query("pkover") == 1)
        {
                message_vision("$ņͷ���˿�$N����м�������Ѿ��μӹ���,һ��Сʱ��ɣ���\n",
                               me, this_object());
                return 1;
        }
                if (!userp(me))
            {
                message_vision("$n����˵: �������������BUG��û�ţ���\n",
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
        inv = all_inventory(me);
        for(i=0;i<sizeof(inv);i++) {
                        destruct(inv[i]);

                    }
message("vision", me->name() + "�����ӵ����˽�����\n",
                environment(me), ({ me }));
        return 1;
}
