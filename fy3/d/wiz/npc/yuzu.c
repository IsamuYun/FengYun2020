//By xgchen@zzfy 2001 �Ż�

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "�����","�����","ɵB","�Ҳ�","����","������˯","�л��û��","û���᣿",
                      "�٣�","��!","fuck","FUCK","Fuck","���","��û�л��","����?",
                      "�����̵�","����������","�����","��үү��","��û�д�����","�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������","û���أ�",
     "�����","��ƨ","������","Nnd","������","�����","ȥ����","����",
"�� �� �� ��","�� �� �� ��","F  u  c  k","f  u  c  k","n n d","N N D","S B",
"������","�ƣգã�","F u c k","f u c k","nnd","NND","SB","����","����","ɵb",
                      "mlgb","MLGB","mcb","MCB","����","����","���","ţ��","���","��ƨ","��ʺ","���ү",
"������","����","������","���","С��","caobi","����",});

void create()
{
        set_name("����", ({"yu zu","yuzu"}));
        set("title", HIY"��Ѳ��ʹ��"NOR);
        set("gender", "����" );
        set("age", 30);
        set("per", 25);
        set("long", HIR"һ�����ص����䣬��������׼�������ʲô���¡�\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("str", 50);
   
        set_skill("literate", 800);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("max_force", 1000);
        
        set("no_clean_up",1);
        setup();
//���������Ҫ���ӵ�Ƶ��
        if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
        if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( !clonep() ) CHANNEL_D->register_relay_channel("new");
       if( !clonep() ) CHANNEL_D->register_relay_channel("fy");       
}

void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"Ѳ��ʹȻ���֣��ӳ����ף�һ�¾���ס$N�Ĳ��ӡ�\n$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=60;//��������Զ�����ʱ��,60=60����
                    
                    result = sprintf("%s��%sƵ��˵�໰(%s)�������� %d ��\n",
                    criname,channel,msg,howlong);
                    
                    criminal->set("qiushi/howlong",howlong);
                    criminal->set("qiushi/temp",result);
                    criminal->move("/d/wiz/qiushi");
                 
                    message("channel:rumor",HIM"��ҥ�Ի��ڡ�ĳ�ˣ���˵ "HIR+criname+HIM" �ڹ���Ƶ��ʹ�ô��������Ѳ��ʹץ���ˡ�\n"NOR, users());
                    return;
                    }
        }
}
