// void.c (re-created after Elon screwed it up on 07-24-95)

inherit ROOM;

void create()
{
	set("short","�ն�");
	set("long",@LONG	
		     ';,,       ',  ;,,,,,,,;,
		 ,;,,,,;,,,,,;,  ;; ;;     ;;
		';'  ;, ;,  ;' ',   ;;''''';;
		   ,;'   ';,,   ;;  ;; ;'; ;;
		  ',,,,,,;,'      ,;;; ; ; ;;
		      ;;       ',;; ;; ;'; ;;
		      ;;        ;;, ;;   , ;;
		 ,,,,,;;,,,,;,   ;','     ';'

LONG
	);
	set("no_clean_up",1);
        set("exits", ([ /* sizeof() == 2 */
  "north" : "d/fy/fysquare"
]));
	replace_program(ROOM);
}

