﻿//#include ../cfb.js
var mod = new CfModule('inheritance1', 'ns');
var interface = mod.addInterface('ife');
var func = interface.addFunc('Fx1', cfb.Types.vt_int32);
func.addArg('Arg', cfb.Types.vt_bool);
var cls = mod.addCls('cls');
cls.addProp('PBool', cfb.Types.vt_bool);
var cls2 = mod.addCls('cls2');
cls2.addProp('PInt', cfb.Types.vt_int32);
cls2.baseClass = cls.path();
cls2.addInterface(interface.path());
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
