// book.c

inherit ITEM;

void create()
{
        set_name( "������", ({ "yaoqin", "qin" }));
        set_weight(8);
        set("unit", "��");
        set("long", "����һ���ð������ɵ����٣�����д��һЩ�㲻ʶ�Ĺ�׭�֡�\n");
        set("value", 2);
        set("skill", ([
                "name":                 "jiayiforce",
                "exp_required": 5000,                
                "sen_cost":             40,     
                "difficulty":   50,            
                "max_skill":    10           
        ]) );
}
