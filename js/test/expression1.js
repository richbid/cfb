﻿//#include ../cfb.js
var mod = new CfModule('expression1', 'ns');
var cls = mod.addCls('cls');
cls.addProp('PBool', cfb.Types.vt_bool);
var func = cls.addFunc('Func', cfb.Types.vt_int32);
func.addExpression(cfb.Types.vt_int32, 'localField = 1 + 1;');
func.addExpression(cfb.Types.vt_double, 'GlobalField = 1.1 * -2.2;');

cls.namespace = 'csns';
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cls.namespace = 'javans';
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cls.namespace = 'qtns';
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
