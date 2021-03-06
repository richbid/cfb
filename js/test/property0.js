﻿//#include ../cfb.js
var mod = new CfModule('property0', 'ns');
var cls = mod.addCls('cls');
cls.addProp('PBool', cfb.Types.vt_bool);
cls.addProp('PBytes', cfb.Types.vt_bytes);
cls.addProp('PDate', cfb.Types.vt_date);
cls.addProp('PDateTime', cfb.Types.vt_datetime);
cls.addProp('PDouble', cfb.Types.vt_double);
cls.addProp('PFloat', cfb.Types.vt_float);
cls.addProp('PInt32', cfb.Types.vt_int32);
cls.addProp('PText', cfb.Types.vt_text);
cls.addProp('PTime', cfb.Types.vt_time);
cls.addProp('PUInt32', cfb.Types.vt_uint32);
cls.namespace = 'csns';
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cls.namespace = 'javans';
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cls.namespace = 'qtns';
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
