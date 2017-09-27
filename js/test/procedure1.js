//#include ../cfb.js
var mod = new CfModule('procedure1', 'ns');
var cls = mod.addCls('cls');
cls.addProp('PBool', cfb.Types.vt_bool);
var proc = cls.addProc('Proc');
proc.addArgs([
        [ 'ArgBool', cfb.Types.vt_bool ],
        [ 'ArgBytes', cfb.Types.vt_bytes ],
        [ 'ArgDate', cfb.Types.vt_date ],
        [ 'ArgDateTime', cfb.Types.vt_datetime ],
        [ 'ArgDouble', cfb.Types.vt_double ],
        [ 'ArgFloat', cfb.Types.vt_float ],
        [ 'ArgInt32', cfb.Types.vt_int32 ],
        [ 'ArgText', cfb.Types.vt_text ],
        [ 'ArgTime', cfb.Types.vt_time ],
        [ 'ArgUInt32', cfb.Types.vt_uint32 ]
]);
cls.namespace = 'csns';
cfb.build(mod, 'y:/cfb-git/cs', 'y:/cfb-git/templates', cfb.Templates.tp_cs2010, cfb.False, cfb.False, null, null);
cls.namespace = 'javans';
cfb.build(mod, 'y:/cfb-git/java', 'y:/cfb-git/templates', cfb.Templates.tp_java, cfb.False, cfb.False, null, null);
cls.namespace = 'qtns';
cfb.build(mod, 'y:/cfb-git/qt', 'y:/cfb-git/templates', cfb.Templates.tp_qtWindows, cfb.False, cfb.False, null, null);
