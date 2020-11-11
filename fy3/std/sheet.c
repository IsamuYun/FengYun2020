// yiru@hero 2000.8.5
// sheet.c

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

// 符放在 /obj/sheet 目录下，是为了能够正确的设置其 euid 和 uid
// /obj/ 目录下的物件的 euid 与其创建者的用户 euid 相同。
// 如果被放到例如是 /d/testcave/obj 之类的目录中， euid 就不正常了
// 因为本程序中需要 euid 与用户 euid 相同，所以必须注意这个问题。

void setup()
{
        seteuid(getuid());
    set("long", "这是一张" + name() +"。\n");
}

int unequip()
{
        set("equipped", 0);
        return 1;
}

void init()
{
    // 一张最普通的符有这么几个基本功能
    add_action("do_burn", "burn");
    add_action("do_write", "write");
    add_action("do_attach", "attach");
}

int burn_function();
int attach_function(object ob);
int write_function(object ob);

int do_burn(string target)
{
    object ob, me;
    me = this_player();

    if( !target ){
        // 当输入格式不正确时，不考虑将该命令转到其他物件处理，因此要返回 1 
        write("指令格式：burn <符>\n");
        return 1;
    }

    // 判断是否存在指定要烧的符。
    if( !(ob = present(target, me
)) ){
        // 不考虑将该命令转到其他物件处理，因此要返回 1 
        write("你身上没有"+target+"。\n");
        return 1;
    }

    if( me->is_busy() ){
        write("你上个动作还未完成，不能烧符。\n");
        return 1;
    }

    // 判断是否是本对象接收的 burn 指令，这一项尤其重要！
    // 身上有多张符的时候，应当互相传递 burn 指令，因此需要返回 0。
    if( ob != this_object() ) {
        return 0;
    }


    if( environment(me)->query("no_magic") ){
        write("这里不能烧符。\n");
        return 1;
    }

    me->start_busy(1);

    // 事实证明这里似乎确实可以返回 1
    return burn_function();
}
 
int do_attach(string arg)
{
    string target;
    object ob, me = this_player();

    if( !arg ){
        // 当输入格式不正确时，不考虑将该命令转到其他物件处理，因此要返回 1 
        write("指令格式：attach <符> to <目标>\n");
        return 1;
    }

    if( me->is_busy() ){
        write("你上个动作还未完成，不能施符。\n");
        return 1;
    }

    if( sscanf(arg,"%s to %s",arg,target)!=2 ){
        write("指令格式：attach <符> to <目标>\n");
        return 1;
    }

    // 判断是否存在指定要贴的符。
    if( !(ob = present(arg, me)) ){
        // 不考虑将该命令转到其他物件处理，因此要返回 1 
        write("你身上没有"+arg+"。\n");
        return 1;
    }

    // 判断是否是本对象接收的 attach 指令，这一项尤其重要！
    // 身上有多张符的时候，应当互相传递 attach 指令。
    if( ob!=this_object() ) 
        return 0;

    // 既然ob==this_object() ，ob就可以挪作他用了。

    // 判断是否存在指定要贴的目标。
    if( !(ob = present(target, environment(me))) ){
        // 不考虑将该命令转到其他物件处理，因此要返回 1 
        write("这里没有"+target+"。\n");
        return 1;
    }

    me->start_busy(1);

    return attach_function(ob);
}

int do_write(string arg)
{
    string target;
    object ob, me = this_player();

    if( !arg ){
        // 当输入格式不正确时，不考虑将该命令转到其他物件处理，因此要返回 1 
        write("指令格式：write <目标> on <符>\n");
        return 1;
    }

    if( me->is_busy() ){
        write("你上个动作还未完成，不能写字。\n");
        return 1;
    }

    if( sscanf(arg,"%s on %s",target,arg)!=2 ){
        write("指令格式：write <目标> on <符>\n");
        return 1;
    }

    // 判断是否存在指定要贴的符。
    if( !(ob = present(arg, me)) ){
        // 不考虑将该命令转到其他物件处理，因此要返回 1 
        write("你身上没有"+arg+"。\n");
        return 1;
    }

    // 判断是否是本对象接收的 attach 指令，这一项尤其重要！
    // 身上有多张符的时候，应当互相传递 attach 指令。
    if( ob!=this_object() ) 
        return 0;

    // 既然ob==this_object() ，ob就可以挪作他用了。

    // 判断是否存在指定要贴的目标。
    ob = present(target, environment(me));
    if(!ob) ob = find_player(target);
    if(!ob) ob = find_living(target);

    delete("targetname");
    if(!ob){
        set("targetname", target);
        message_vision("$N把" + target + "写在$n上。\n", me, this_object());
        set("long",
            "这是一张" + name() + "，上面写着『" + target + "』几个小字。\n");
    }else{
        set("targetname", ob);
        message_vision("$N把" + ob->name() + "写在$n上。\n", me, this_object());
        set("long",
            "这是一张" + name() + "，上面写着『" + ob->name() + "』。\n");
    }

    me->start_busy(1);

    if(ob) write_function(ob);

    return 1;
}

int burn_function()
{
    message_vision( "$N烧掉了一张"+name()+"。\n", this_player());
    destruct(this_object());
    return 1;
}
int write_function(object ob)
{
    return 1;
}
int attach_function(object ob)
{   
    message_vision( "$N拿出一张"+name()+"往$n一贴。\n", this_player(),ob);
    destruct(this_object());
    return 1;
}

