/* See LICENSE file for copyright and license details. */

/* done dwm-actualfullscreen-20211013-cb3f58a.diff*/
/* done dwm-bartoggle-keybinds-6.4.diff */
/* done dwm-cfacts-vanitygaps-6.4_combo.diff */
/* done dwm-colorbar-6.3.diff */
/* done dwm-cool_autostart-6.5.diff */
/* done dwm-fixmultimon-6.4.diff */
/* done dwm-focusmaster-return-6.2.diff */
/* done dwm-hide_vacant_tags-6.4.diff */
/* done dwm-restartsig-20180523-6.2.diff */
/* done dwm-preventfocusshift-20240831-6.5.diff*/
/* done dwm-swallow-6.3.diff */
/* done dwm-statuscmd-20241009-8933ebc.diff */
/* done dwm-systray-20230922-9f88553.diff */
/* done dwm-xrdb-6.4.diff */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int showtitle          = 1;        /* 0 means no title */
static const int showtags           = 1;        /* 0 means no tags */
static const int showlayout         = 1;        /* 0 means no layout indicator */
static const int showstatus         = 1;        /* 0 means no status bar */
static const int showfloating       = 1;        /* 0 means no floating indicator */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=13" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font::size=13";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
        [SchemeNorm]            = { normfgcolor, normbgcolor, normbordercolor },
        [SchemeSel]             = { selfgcolor,  selbgcolor,  selbordercolor  },
        [SchemeStatus]          = { normfgcolor, normbgcolor,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
        [SchemeTagsSel]         = { selfgcolor, selbgcolor,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
        [SchemeTagsNorm]        = { normfgcolor, normbgcolor,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
        [SchemeInfoSel]         = { selfgcolor, selbgcolor,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
        [SchemeInfoNorm]        = { normfgcolor, normbgcolor,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

static const char *const autostart[] = {
        "xrandr", "--output", "HDMI-1-0", "--mode", "1920x1080", "--refresh", "144", "--right-of", "eDP-1", "--noprimary", NULL,
        "dunst", "-c", "$HOME/.config/dunst/dunstrc", "-startup-notification", "&", NULL,
        "picom", NULL,
        "flameshot", NULL,
        "wal", "-i", "/home/jraj/Pictures/wallies/wall_16.jpg", NULL,
        "slstatus", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance        title                         tags mask  isfloating  isterminal  noswallow  monitor */
	{ "firefox",            NULL,           NULL,                          1,         0,          0,          -1,         1 },
	{ "zen",                "Toolkit",      "Picture-in-Picture",          0,         1,          0,          -1,         -1 },
	{ "zen",                NULL,           NULL,                          1,         0,          0,          -1,         0 },
	{ NULL,                 NULL,           "Event Tester",                0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 144;  /* refresh rate (per second) for client move/resize */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " ",      tile },    /* first entry is default */
	{ " ",      monocle },
	{ "󰼸 ",      spiral },
	/*{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },*/
	{ "󰜺 ",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL } 
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normfgcolor, "-nf", normbgcolor, "-sb", selbordercolor, "-sf", selbgcolor, "-l", "10", NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *browser[]  = { "zen-browser", NULL };
static const char *launcher[]  = { "rofi", "-show", "drun", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = launcher } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      spawn,          {.v = browser } },
	{ MODKEY,                       XK_v,      spawn,          SHCMD ("/home/jraj/.config/scripts/volumeswitch.sh") },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          SHCMD ("pavucontrol") },

	{ MODKEY,                       XK_i,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      incnmaster,     {.i = -1 } },

	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_Return, zoom,           {0} },

	{ MODKEY|ControlMask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|ControlMask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|ControlMask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|ControlMask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|ControlMask|ShiftMask,    XK_0,      defaultgaps,    {0} },

	{ 0,                            XF86XK_MonBrightnessUp,     spawn,          SHCMD("$HOME/.config/scripts/brightness.sh up") },
	{ 0,                            XF86XK_MonBrightnessDown,   spawn,          SHCMD("$HOME/.config/scripts/brightness.sh down") },
	{ 0,                            XF86XK_AudioLowerVolume,    spawn,          SHCMD("$HOME/.config/scripts/volume.sh -d") },
	{ 0,                            XF86XK_AudioRaiseVolume,    spawn,          SHCMD("$HOME/.config/scripts/volume.sh -u") },
	{ 0,                            XF86XK_AudioMute,           spawn,          SHCMD("$HOME/.config/scripts/volume.sh -m") },

	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },

	{ MODKEY|ControlMask,           XK_t,      togglebartitle, {0} },
	{ MODKEY|ControlMask,           XK_s,      togglebarstatus,{0} },
	{ MODKEY|ShiftMask,             XK_t,      togglebartags,  {0} },
	{ MODKEY|ShiftMask,             XK_s,      togglebarlt,    {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglebarfloat, {0} },

	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	{ MODKEY,                       XK_r,     xrdb,           {.v = NULL } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY,                       XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
