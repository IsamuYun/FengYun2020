// doc.c
// atu@sjfy
// 整理文件，有玩家在线的时候最好不使用此指令。 2000/11/16
// 目前只提供NPC、ROOM、ITEM的整理，以后有时间再加其他种类吧。tied.. atu
// 大家可以在这个基础上进一步完善其他功能希望大家能保留
// 以上文字。
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object);   
void QueryNpcInfo(string);
void QueryRoomInfo(string);
void QueryItemInfo(string);
string QuerySkill(object);
string QueryAction(object,object);
string QueryEquipProp(object,mapping);

int main(object me,string arg)
{
    string path,var;
    string *filename;

    if( !arg) {
    	// sscanf(arg,"%s %s",path,var) != 2){
        return help(me);
    }
    if(file_size(path = resolve_path(me->query("cwd"),path)) != -2 )
        return notify_fail("没有这个目录！\n");
    seteuid(getuid());
    if(path[sizeof(path)-1] != '/')
        path += "/";
    switch(var)
    {
        case "-npc":
        case "-NPC":
            QueryNpcInfo(path);
            break;
        case "-room":
        case "-ROOM":
            QueryRoomInfo(path);
            break;
        case "-item":
        case "-ITEM":
            QueryItemInfo(path);
            break;
        default:
            write("参数不对，请重新输入！\n");
            break;
    }
    return 1;
}
void QueryNpcInfo(string path)
{
    string filename;
    string *file;
    object obj;
    int num=0;
    filename=path+"文档归类之NPC篇";
    
    if(file_size(filename)＞0)
        rm(filename);
    file=get_dir(path);
    foreach(string tmp in file){
        if (file_size(tmp) == -2)
            continue;
        write(sprintf("  整理（%-15s）中...",tmp));
        reset_eval_cost();
        obj=new(path + tmp);
        if (!objectp(obj) ){
            write(HIR" ...失败！\n"NOR);
            continue;
        }
        if(!obj-＞is_character() // !obj-＞query("name")){
            write(HIR"NOT NPC！\n"NOR);
            continue;
        }
        num ++;
    write_file(filename,HIG"==================================================\n"NOR,0);
    write_file(filename,HIR"文件序号："NOR+num+"\n",0);
    write_file(filename,HIR"文件名称："NOR+tmp+"\n",0);
    write_file(filename,HIW"中文名字："NOR+obj-＞query("name")+"\n",0);
    write_file(filename,HIW"英文ＩＤ: "NOR + sprintf("%s",implode(obj-＞parse_command_id_list(), ","))+"\n",0);
    write_file(filename,QuerySkill(obj),0);
    write_file(filename,"─────────────────────────\n");
    write_file(filename,sprintf("【 精 力 】%10d      【 灵　力 】%d \n",
            obj-＞query("max_gin"),obj-＞query("max_atman")));
    write_file(filename,sprintf("【 气 血 】%10d      【 内　力 】%d (+%d)\n",
            obj-＞query("max_kee"),obj-＞query("max_force"),obj-＞query("force_factor")));
    write_file(filename,sprintf("【 心 神 】%10d      【 法　力 】%d \n",
            obj-＞query("max_sen"),obj-＞query("max_mana")));
    write_file(filename,sprintf("【 经 验 】%10d      【 正  气 】%d \n",
            obj-＞query("combat_exp"),obj-＞query("shen")));
        destruct(obj);
        write(HIY" ...成功。 \n"NOR);
    }
    write_file(filename,"==================================================\n",0);
    write_file(filename,"    本目录下总共有"HIG+num+NOR"个NPC文件！\n",0);
    write("=========================================\n");
    write("      共整理（"HIG+chinese_number(num)+NOR"）个NPC文件   \n\n");
}
void QueryRoomInfo(string path)
{
    string filename;
    string *file;
    object obj;
    object finder=new("/obj/npc/void_npc");
    
    int num=0;
    filename=path+"文档归类之ROOM篇";
    
    if(file_size(filename)＞0)
        rm(filename);
    file=get_dir(path);
    foreach(string tmp in file){
        if (file_size(path+tmp) == -2)
            continue;
        write(sprintf("  整理（%-15s）中...",tmp));
        reset_eval_cost();
        obj=load_object(path+tmp);
        if (!objectp(obj) ){
            write(HIR" ...失败！\n"NOR);
            continue;
        }
        if( obj-＞is_character() // !stringp(obj-＞query("short")) ){
            write(HIR"NOT ROOM\n"NOR);
            continue;
        }
        num ++;
        write_file(filename,"─────────────────────────\n",0);
        write_file(filename,YEL"房间序号："WHT+num+"\n"NOR,0);
        write_file(filename,YEL"房间名称："WHT+obj-＞query("short")+"("+tmp+")\n"NOR,0);
        write_file(filename,YEL"房间坐标："WHT"（"+obj-＞query("coor/x")+","
                   +obj-＞query("coor/y")+","+obj-＞query("coor/z")+"）\n"NOR,0);
        write_file(filename,QueryAction(obj,finder),0);
        if(mapp(obj-＞query("coor")))
            write(HIY" ...成功\n"NOR);
        else
            write(HIY" ...成功"HIR"（无坐标）\n"NOR);
    }
    write_file(filename,"==================================================\n",0);
    write_file(filename,"    本目录下总共有"HIG+num+NOR"个房间！\n",0);
    write("=========================================\n");
    write("      共整理（"HIG+chinese_number(num)+NOR"）个房间文件   \n\n");
    destruct(finder);
}
void QueryItemInfo(string path)
{
    string filename;
    string *file;
    object obj;
    mapping prop;
    
    int num=0;
    int flag=0;
    filename=path+"文档归类之ITEM篇";
    
    if(file_size(filename)＞0)
        rm(filename);
    file=get_dir(path);
    foreach(string tmp in file){
        if (file_size(path+tmp) == -2)
            continue;
        write(sprintf("  整理（%-15s）中...",tmp));
        reset_eval_cost();
        obj=new(path + tmp);
        if (!objectp(obj) ){
            write(HIR" ...失败！\n"NOR);
            continue;
        }
        if( obj-＞is_character() // !stringp(obj-＞query("name")) ){
            write(HIR"NOT ITEM\n"NOR);
            continue;
        }
        num ++;
        write_file(filename,HIG"─────────────────────────\n"NOR,0);
        write_file(filename,WHT"物品序号："NOR+num+"\n",0);
        write_file(filename,WHT"物品名称："NOR+obj-＞query("name")+"("+
                    implode(obj-＞parse_command_id_list(),",")+")\n",0);
        write_file(filename,WHT"物品价格："NOR+MONEY_D-＞price_str((int)obj-＞query("value"))+"\n",0);
/*
        if(mapp(prop=obj-＞query("weapon_prop")))
            QueryEquipProp(obj,prop);
        else if(mapp(prop=obj-＞query("armor_prop")))
            QueryEquipProp(obj,prop);
*/
        destruct(obj);
        write(HIY" ...成功。 \n"NOR);
    }
    write_file(filename,"==================================================\n",0);
    write_file(filename,"    本目录下总共有"HIG+num+NOR"个物品！\n",0);
    write("=========================================\n");
    write("      共整理（"HIG+chinese_number(num)+NOR"）个物品文件   \n\n");
}
string QueryAction(object ob,object finder)
{
    mixed *cmds;
    string msg="",*str,name;
    int count=0;

    if (stringp(ob-＞query("short")))
        name=ob-＞query("short");
    else name=ob-＞query("name");

    finder-＞move(ob);
    cmds = finder-＞query_commands();
    if ( sizeof(cmds) == 1)
        return("          "+name+ "没有提供任何指令。\n");
    msg += "          "CYN+name +"提供如下指令：\n"NOR;
    foreach(mixed cmd in cmds){
        if( cmd[2]==finder ) continue;
        msg+=sprintf(WHT"%-10s   "NOR, cmd[0]);
        count++;
        if(count%4==0)
            msg+="\n";
    }
    msg+="\n";
    return msg;
}
string QuerySkill(object ob)
{
    mapping m_skills,m_enable;
    string *sname;
    int i, jibie, lingwu, jilei,xiuwei, opt_all;    
    string msg="";

    m_skills = ob-＞query_skills();
    if ( !sizeof(m_skills) )
        return("          "+ob-＞name() + "没有任何武功。\n");
    msg += "          "+ob-＞name() +"目前所学过的技能：\n";
    m_enable = ob-＞query_skill_map();
    if ( !mapp(m_enable) ) m_enable = ([]);
    sname=keys(m_skills);
    msg=msg+"─────────────────────────\n";
    for ( i = 0; i ＜ sizeof( m_skills ); i++ ){
        msg=msg+sprintf( "%s%-12s%-28s%8d\n",
            m_enable[ sname[i] ] ? HIW"＊"NOR : "  ",
            to_chinese(sname[i]),  " 〖" + sname[i] + "〗",
            m_skills[sname[i]]);        
        }
    return msg;
}
string QueryEquipProp(object equip,mixed props)
{
    string type,msg="";
    int *special_props,i;
    int count=0;
    string *prop;

    if(stringp(type=equip-＞query("skill_type")))
        msg+=sprintf("兵器类型：%-10s     攻 击 力：%d",type,(int)equip-＞query("weapon_porp/damage"));
    else if(stringp(type=equip-＞query("skill_type")))
        msg+=sprintf("防具类型：%-10s     防 御 力：%d",type,(int)equip-＞query("armor_porp/armor"));
    if ( !sizeof(props))
        return("          "+equip-＞name()+ "没有提供任何指令。\n");
    msg += "          "+equip-＞name()+"的其他功效：\n";
    prop=keys(props);
    for (i=0;i＜sizeof(props);i++){
//    foreach(string prop in props){
        if( prop[i]=="armor"//prop[i]=="damage")
            continue;
        msg+=sprintf(WHT"%-12d  "NOR, props[prop[i]]);
        if(i%4==0)
            msg+="\n";
    }
    return msg;
}

int help(object me)
{
    write(@HELP
指令格式：doc 路径名 -种类名 
目前提供的种类有：room、npc、item
例：
    doc /d/fy/npc -npc
有玩家在线时最好不使用此指令。
HELP);
    return 1;
}