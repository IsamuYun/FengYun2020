// An example book

inherit ITEM;

void create()
{
        set_name("�׼�ȭ��Ҫּ", ({ "book" }));
        set_weight(600);
        set("unit", "��");
        set("long",
                
"����һ������ �׼�ȭ���������飬����ȭ����ѩͤ������ȭʦ�洫��ȭ��\n"
                
"����ѧ�׶����Ȿ����Ȼֻ����������ȭ�����ŵĹ��򣬵�������������\n"
                "���㲻���ˣ��ʺϳ�ѧ�ߡ�\n");
        set("value", 100);
        set("skill", ([
                "name":                 "bai-quan",             // name of 
                "exp_required": 0,                              // minimum 
                "sen_cost":             40,                             // 
                "difficulty":   20,                             // the base 
                "max_skill":    10                              // the 
        ]) );
}
 
