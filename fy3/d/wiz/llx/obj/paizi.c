inherit ITEM;

void create()
{
        set_name("�ι���֪", ({ "paizi" }) );
        set_weight(500);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "��");
                set("long", "��ӭ������������ͣ��������Ѵ�ң������ſ����˰ɣ��ã��Ǵ�Ҿ���㿴���ɡ�
��ʵ���˶���Ҳ������Ĳ��ܰ�ȫ��ȥ�ˣ��������ģ�qiurao����
�Ժ�����Ҫ½������һЩ������ʩ����ӭ�ٴι��١�\n");
                set("value", 1);
        }
}

int is_container()
{
return 1;
}
