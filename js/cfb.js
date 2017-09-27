
// use '//#include' to include extern javascript files, which may be a script tree, each line must start with '//#include'
//<core frame builder>
var cfb = {
    NullText: '',
    True: 1,
    False: 0,
    Tasks: {
        tk_data: 'tk_data',
        tk_filesys: 'tk_filesys',
        tk_memio: 'tk_memio',
        tk_networks: 'tk_networks',
        tk_threads: 'tk_threads',
        tk_widgets: 'tk_widgets',
        tk_database: 'tk_database'
    },
    Scopes: {
        sc_private: 'private',
        sc_public: 'public',
        sc_protected: 'protected',
    },
    Types: {
        vt_unknown: 'vt_unknown',
        vt_bool: 'vt_bool',
        vt_float: 'vt_float',
        vt_double: 'vt_double',
        vt_int32: 'vt_int32',
        vt_uint32: 'vt_uint32',
        vt_text: 'vt_text',
        vt_date: 'vt_date',
        vt_time: 'vt_time',
        vt_datetime: 'vt_datetime',
        vt_bytes: 'vt_bytes',
        vt_class: 'vt_class'
    },
    Templates: {
        tp_cs2010: 'template4CS2010',
        tp_java: 'template4Java',
        tp_qtAndroid: 'template4QtAndroid',
        tp_qtWindows: 'template4QtWindows'
    },
    Default: {
        Function : {
            enableHash : 1,
            isPrivate : 0,
            isStatic : 0,
            isForList : 0,
            returnAsArgument : 1,
            enableLog : 1,
            isProcedure : 0,
            isCircuitItem : 0,
        },
        Property : {
            readonly : 0,
            constructable : 1,
            isStatic : 0,
            hasRange : 0,
        },
        Class : {
            serializable : 1,
            widgetVisible : 0,
            inheritable : 1,
            variableScope : 'public',
            isInterface : 0,
            jsonOnly : 0,
            useTextCoders : 1,
            enableFunctionParser : 1,
            enableEnumKeyValues : 1,
        },
        Module : {
            javaVersion : '7',
        }
    },
    releaseModule : function (modHash) {
        //release a module memory tree
        //modHash : int
        return cfb_releaseModule(modHash);
    },
    addModule: function (modName) {
        //add a module
        //modName : string
        return cfb_addModule(modName);
    },   
    addClass: function (modHash, clsName, serial, widgetVisible, clsNs) {
        //add a class to a module
        //modHash : int
        //clsName : string not null
        //serial : bool 0 1
        //widgetVisible : bool 0 1
        //clsNs : string
        return cfb_addClass(modHash, clsName, serial, widgetVisible, clsNs);
    },
    addClassTask: function (clsHash, clsTask) {
        //add a task to a class
        //clsHash : int
        //clsTask : string not null
        return cfb_addClassTask(clsHash, clsTask);
    },
    addProperty: function (clsHash, propName, typeName, usage, readOnly, constructable, isStatic, label, hasRange) {
        //add a property to a class
        //clsHash : int
        //propName : string not null
        //typeName : string not null
        //usage : string
        //readOnly : bool 0 1
        //constructable : bool 0 1
        //isStatic : bool 0 1
        //label : string
        //hasRange: bool 0 1, include range functions
        return cfb_addProperty(clsHash, propName, typeName, usage, readOnly, constructable, isStatic, label, hasRange);
    },
    addArguments: function () {
        //add a arguments, return an argsHash, which is an int
        return cfb_addArguments();
    },
    addArgument: function (argsHash, argName, typeName, usage) {
        //add a hash to an arguments
        //argsHash : int
        //argName : string not null
        //typeName : string not null
        //usage : string
        return cfb_addArgument(argsHash, argName, typeName, usage);
    },
    addFunctionContent: function (clsHash, funcName, todo, argsHash, retTypeName, isPrivate, isStatic, label, forList, subFuncList, body) {
        //add a function to a class, with codes content
        //clsHash : int
        //funcName : string not null
        //todo : string
        //argsHash : int
        //retTypeName : string
        //isPrivate : bool 0 1
        //isStatic : bool 0 1
        //label : string
        //forList : string
        //subFuncList : string
        //body : string, first line should mark as //cpp, //cs or //java, and lines should join with \n
        return cfb_addFunctionContent(clsHash, funcName, todo, argsHash, retTypeName, isPrivate, isStatic, label, forList, subFuncList, body);
    },
    addFunction: function (clsHash, funcName, todo, argsHash, retTypeName, isPrivate, isStatic, label, forList) {
        //add a function to a class, without codes content
        //clsHash : int
        //funcName : string not null
        //todo : string
        //argsHash : int
        //retTypeName : string
        //isPrivate : bool 0 1
        //isStatic : bool 0 1
        //label : string
        //forList : bool 0 1
        return cfb_addFunction(clsHash, funcName, todo, argsHash, retTypeName, isPrivate, isStatic, label, forList);
    },
    setNextFunction: function (functionPath, nextFunction) {
        //** incorrect design causes infinite route and stack overflow, add infinity validation in the future.
        //functionPath: format is 'Module.Class.Function', ignore isStatic or isPrivate, no arguments
        //nextFunction: next function handler, can be fx0,fx1,fx2... or single fx
        //for a circuit class, all functions must have same return type
        return cfb_setNextFunction(functionPath, nextFunction);
    },
    addExpression: function (functionPath, type, expression) {
        //add expression to function body, if function has body then ignore it
        //functionPath: format is 'Module.Class.Function', ignore isStatic or isPrivate, no arguments
        //type: cfb.Types
        //expression: string not null
        return cfb_addExpression(functionPath, type, expression);
    },
    setNextIfFunction: function (functionPath, testFunction, trueFunction, falseFunction) {
        //** incorrect design causes infinite route and stack overflow, add infinity validation in the future.
        //functionPath: format is 'Module.Class.Function', ignore isStatic or isPrivate, no arguments
        //testFunction: function return value should be 0 or not 0
        //trueFunction: true function handler, can be fx0,fx1,fx2... or single fx
        //falseFunction: false function handler, can be fx0,fx1,fx2... or single fx
        //for a circuit class, all functions must have same return type
        return cfb_setNextIfFunction(functionPath, testFunction, trueFunction, falseFunction);
    },
    setNextWhileFunction: function (functionPath, whileFunction, functions) {
        //** incorrect design causes infinite route and stack overflow, add infinity validation in the future.
        //functionPath: format is 'Module.Class.Function', ignore isStatic or isPrivate, no arguments
        //whileFunction: function return value should be 0 or not 0
        //functions: can be fx0,fx1,fx2... or single fx
        //for a circuit class, all functions must have same return type
        return cfb_setNextWhileFunction(functionPath, whileFunction, functions);
    },
    setNextSwitchFunction: function (functionPath, switchFunction, caseFunctions) {
        //** incorrect design causes infinite route and stack overflow, add infinity validation in the future.
        //functionPath: format is 'Module.Class.Function', ignore isStatic or isPrivate, no arguments
        //switchFunction: function return value should be 0, 1, 2
        //caseFunctions: fx0,fx1,fx2
        //for a circuit class, all functions must have same return type
        return cfb_setNextSwitchFunction(functionPath, switchFunction, caseFunctions);
    },
    addVirtualFunction: function (clsHash, funcName, todo, argsHash, retTypeName) {
        //add a virtual function to a class, with codes content
        //a virtual function is a function that is included in an inheritable class and not private
        //clsHash : int
        //funcName : string not null
        //todo : string
        //argsHash : int
        //retTypeName : string
        return cfb_addFunction(clsHash, funcName, todo, argsHash, retTypeName, 0, 0, '', 0);
    },
    setInheritable: function (clsHash, inheritable) {
        //set a class to be inheritable
        //clsHash : int
        //inheritable : bool 0 1
        return cfb_setInheritable(clsHash, inheritable);
    },
    setBaseClass: function (clsHash, baseCls) {
        //set a super/base class to a class
        //clsHash : int
        //baseCls : string not null
        return cfb_setBaseClass(clsHash, baseCls);
    },
    addInterface: function (clsHash, interfaceCls) {
        //add an interface to a class, just as inherit an interface and its functions
        //clsHash : int
        //interfaceCls : string not null
        return cfb_addInterface(clsHash, interfaceCls);
    },
    packModule: function (modHash, prjName, outDir) {
        //output a module to files or a zip file
        //modHash : int
        //prjName : string not null
        //outDir : string not null
        return cfb_packModule(modHash, prjName, outDir);
    },
    addEnumeration: function (classPath, eName, values) {
        //add an enumeration to a class
        //classPath: namespace.className
        //eName: enumeration's name
        //values: aa,bb,cc
        //example: addEnumeration('ns.cls', 'MyEnu', 'me1,me2,me3'), no {}
        return cfb_addEnumeration(classPath, eName, values);
    },
    addConstant: function (classPath, cName, type, value) {
        //add a constant value (vt_int32, vt_double, vt_text)
        //classPath: namespace.className
        //cName: constant name
        //type: vt_int32, vt_double, vt_text
        //value, int32, double, text
        //example: addConstant('ns.cls', cfb.Types.vt_int32, 'Int32Firm', '100')
        //example: addConstant('ns.cls', cfb.Types.vt_double, 'DoubleFirm', '123456.7890123456')
        //example: addConstant('ns.cls', cfb.Types.vt_text, 'TextFirm', 'My Text')
        return cfb_addConstant(classPath, cName, type, value);
    },
    setClassOption: function (classPath, key, value) {
        //set class option
        //classPath: namespace.className
        //key: string
        //bool keys = { 'jsonOnly','useTextCoders','enableFunctionParser','enableEnumKeyValues' }
        //text keys = { 'variableScope' = cfb.Scopes }
        //value: string        
        return cfb_setClassOption(classPath, key, value);
    },
    setFunctionOption: function (functionPath, key, value) {
        //set function option
        //functionPath: namespace.className.functionName
        //key: string
        //bool keys = { 'enableHash', isPrivate', 'isStatic', 'isFormula', 'forList', 'returnAsArgument', 'enableLog'}
        //text keys = { 'result' }
        //value: string
        return cfb_setFunctionOption(functionPath, key, value);
    },
    build: function (mod, outDir, templatesDir, projectName, package, selfTest, diagram, tags) {
        //mod : CfModule object        
        return cfb_build(mod, outDir, templatesDir, projectName, package, selfTest, diagram, tags);
    },         
    debug: function (key, value) {
        //key : string not null
        //value : string not null
        cfb_debug(key, value);
    },
    setSource: function (path) {
        //set templates folder
        //path : string, relative directory name, full path is '/sdcard/NeoBuilder/<path>'
        cfb_setSource(path);
    },
    alterSource: function (rawName, newName) {
        //alter template name with custom name
        //rawName: string, from cfb.Templates.tp_*
        //newName: string, alternate name, which is a zip file name also, and store in templates folder
        cfb_alterSource(rawName, newName);
    },
    listFiles: function (dirPath) {
        //list files, return an array
        //dirPath : string not null
        return cfb_listFiles(dirPath);
    },
    fileExists: function (filePath) {
        //test a file is existing or not, return 1 or 0
        //filePath : string not null
        return cfb_fileExists(filePath);
    },
    read: function (filePath) {
        //read text from filePath, return a string
        //filePath : string not null
        return cfb_readFile(filePath);
    },
    write: function (filePath, text) {
        //write text to a filePath, return 1 or 0
        //filePath : string not null
        //text : string not null
        cfb_writeFile(filePath, text);
    },
    system: function (cmd) {
        //perform a system shell command, which is an UNSAFE instruction
        //cmd : string not null
        cfb_system(cmd);
    },
    environment: function (key) {
        //get an environment value, return a string
        //key : string not null
        return cfb_environment(key);
    },
    pick: function (textLines, lineTag0, lineTag1) {
        //get lines between lineTag0 and lineTag1, exclude lineTags
        //textLines : string not null, split by <lf>
        //lineTag0 : string not null
        //lineTag1 : string not null
        return cfb_pick(textLines, lineTag0, lineTag1);
    },
    replaceRegEx: function (text, key, value) {
        //text : string not null
        //key : string not null, regular expression
        //value : string not null
        return cfb_replaceRegEx(text, key, value);
    },
    replace: function (text, key, keyBracket, value) {
        //text : string not null
        //key : string not null
        //keyBracket : string not null, <keyBracket> + key + <keyBracket>
        //value : string not null
        return cfb_replace(text, key, keyBracket, value);
    },
    replaceListRegEx: function (text, keys, keySpliter, values, valueSpliter) {
        //text : string not null
        //keys : string not null, regular expression
        //keySpliter : string not null
        //values : string not null
        //valueSpliter : string not null
        return cfb_replaceListRegEx(text, keys, keySpliter, values, valueSpliter);
    },
    replaceList: function (text, keys, keySpliter, keyBracket, values, valueSpliter) {
        //text : string not null
        //keys : string not null
        //keySpliter : string not null
        //keyBracket : string not null
        //values : string not null
        //valueSpliter : string not null
        return cfb_replaceList(text, keys, keySpliter, keyBracket, values, valueSpliter);
    },
    replaceInside: function (text, leftPattern, rightPattern, value, all) {
        //text : string not null
        //leftPattern : string not null
        //rightPattern : string not null
        //value : string not null, replace <leftPattern> + <all text> + <rightPattern> to <value>
        //all : bool 0 1, search all patterns in text
        return cfb_replaceInside(text, leftPattern, rightPattern, value, all);
    },
    scriptPath: function () {
        return cfb_scriptPath();
    },
    zipOpenReading: function (filePath) {
        //open a zip file for reading, return 1 or 0
        //filePath : string not null
        return cfb_zipOpenReading(filePath);
    },
    zipOpenWriting: function (filePath) {
        //open a zip file for writing, return 1 or 0
        //filePath : string not null
        return cfb_zipOpenWriting(filePath);
    },
    zipClose: function (filePath) {
        //close a zip file
        //filePath : string not null
        cfb_zipClose(filePath);
    },
    zipAdd: function (zipFilePath, itemFilePath, text) {
        //add a file to a zip file, which should be opened for writing
        //return 1 or 0;
        //zipFilePath : string not null
        //itemFilePath : string not null
        //text : string not null
        return cfb_zipAdd(zipFilePath, itemFilePath, text);
    },
    zipFetch: function (zipFilePath, itemFilePath) {
        //fetch text from itemFilePath, which should be opened for reading
        //return text as string
        //zipFilePath : string not null
        //itemFilePath : string not null
        return cfb_zipFetch(zipFilePath, itemFilePath);
    }
};
//</core frame builder>

//<core frame constructor>
function CfArgument(name, type) {
    this.name = name;
    this.type = type;
    this.usage = '';
    if (name === null || type === null) return null;
}

function CfFunction(name, type) {
    this.name = name;
    this.namespace = '';
    this.usage = '';    
    this.returnClass = '';
    this.returnType = type;
    this.enableHash = cfb.Default.Function.enableHash;
    this.isPrivate = cfb.Default.Function.isPrivate;
    this.isStatic = cfb.Default.Function.isStatic;
    this.isForList = cfb.Default.Function.isForList;
    this.returnAsArgument = cfb.Default.Function.returnAsArgument;
    this.enableLog = cfb.Default.Function.enableLog;
    this.isProcedure = cfb.Default.Function.isProcedure;
    this.isCircuitItem = cfb.Default.Function.isCircuitItem;
    this.label = ''; //to enable function label, cfClass.widgetVisible should be cfb.True
    this.csBody = '';
    this.javaBody = '';
    this.cppBody = '';
    this.subFunctions = [];
    this.arguments = [];
    this.expressions = [];
    this.formula = '';
    this.result = '';
    this.addExpression = function (type, expression) {
        //some syntax are different in java, c# and c++, for including 'aReturn' may generate incorrect codes
        //type : cfb.Types
        //expression : string
        var kv = new CfKeyValue(type, expression);
        this.expressions.push(kv);
    };
    this.path = function () {
        return this.namespace + '.' + this.name;
    };
    this.addArg = function (name, type) {
        var arg = new CfArgument(name, type);
        this.arguments.push(arg);
        return arg;
    };
    this.addArgs = function (array) {
        for (var n = 0; n < array.length; n++) {
            this.addArg(array[n][0], array[n][1]);
        }
    };    
    this.addSubFunction = function(name) {
        this.subFunctions.push(name);
    };
    if (name === null) return null;
}

function CfProperty(name, type) {
    this.name = name;
    this.type = type;
    this.readOnly = cfb.Default.Property.readonly;
    this.constructable = cfb.Default.Property.constructable;
    this.isStatic = cfb.Default.Property.isStatic;
    this.hasRange = cfb.Default.Property.hasRange;
    this.label = '';
    this.usage = '';
    if (name === null || type === null) return null;
}

function CfKeyValue(key, value) {
    this.key = key;
    this.value = value;
}

function CfClass(name) {
    this.name = name;
    this.namespace = '';
    this.serializable = cfb.Default.Class.serializable;
    this.widgetVisible = cfb.Default.Class.widgetVisible;
    this.baseClass = '';
    this.inheritable = cfb.Default.Class.inheritable;
    this.tasks = [cfb.Tasks.tk_data];
    this.constantText = [];
    this.constantInt32 = [];    
    this.constantDouble = [];   
    this.interfaces = [];
    this.functions = [];
    this.properties = [];
    this.enumerations = [];
    this.variableScope = cfb.Default.Class.variableScope;
    this.isInterface = cfb.Default.Class.isInterface;
    this.jsonOnly = cfb.Default.Class.jsonOnly;
    this.useTextCoders = cfb.Default.useTextCoders;
    this.tags = [];
    this.enableFunctionParser = cfb.Default.Class.enableFunctionParser;
    this.enableEnumKeyValues = cfb.Default.Class.enableEnumKeyValues;
    this.addTag = function(tag) {
        this.tags.push(tag);            
    };    
    this.addEnumeration = function (values) {
        if (this.isInterface) return;
        //interface class has no enumeration
        //each line format: name { aa,bb,cc,dd }, which is always set to public, can be changed to others scope under IDE
        this.enumerations.push(values);
    };
    this.addConstantText = function (key, value) {
        if (this.isInterface) return;
        var kv = new CfKeyValue(key, value);
        this.constantText.push(kv);
    };
    this.addConstantInt32 = function (key, value) {
        if (this.isInterface) return;
        var kv = new CfKeyValue(key, value);
        this.constantInt32.push(kv);
    };
    this.addConstantDouble = function (key, value) {
        if (this.isInterface) return;
        var kv = new CfKeyValue(key, value);
        this.constantDouble.push(kv);
    };       
    this.addInterface = function (name) {
        if (this.isInterface) return;
        for (var n = 0; n < this.interfaces.length; n++)
            if (this.interfaces[n] == name) return;

        this.interfaces.push(name);
    };
    this.path = function () {
        return this.namespace + '.' + this.name;
    };
    this.listPath = function () {
        return this.namespace + '.' + this.name + 'List';
    };
    this.addProp = function (name, type) {
        if (this.isInterface) return;
        var prop = new CfProperty(name, type);
        this.properties.push(prop);
        return prop;
    };
    this.addProps = function (array) {
        if (this.isInterface) return;
        for (var n = 0; n < array.length; n++) {
            this.addProp(array[n][0], array[n][1]);
        }
    };
    this.addProc = function (name) {
        var proc = new CfFunction(name, cfb.Types.vt_unknown);
        proc.isProcedure = true;
        proc.namespace = this.namespace + '.' + this.name;
        this.functions.push(proc);
        return proc;
    };
    this.addProcs = function(array) {
        for (var n = 0; n < array.length; n++) {
            this.addProc(array[n]);
        }
    };
    this.addFunc = function (name, type) {
        var func = new CfFunction(name, type);
        var returnClass =
            type != cfb.Types.vt_unknown &&
            type != cfb.Types.vt_bool &&
            type != cfb.Types.vt_int32 &&
            type != cfb.Types.vt_uint32 &&
            type != cfb.Types.vt_bytes &&
            type != cfb.Types.vt_float &&
            type != cfb.Types.vt_double &&
            type != cfb.Types.vt_date &&
            type != cfb.Types.vt_datetime &&
            type != cfb.Types.vt_time &&
            type != cfb.Types.vt_text;
        if (returnClass) {
            func.returnClass = type;
            func.type = cfb.Types.vt_class;
        }
        proc.isProcedure = false;
        func.namespace = this.namespace + '.' + this.name;
        this.functions.push(func);
        return func;
    };
    this.addFuncs = function(array) {
        for (var n = 0; n < array.length; n++) {
            this.addFunc(array[n][0], array[n][1]);
        }
    };    
    this.addFormula = function(name, type, formula, isPrivate, isStatic) {
        if (this.isInterface) return;
        var func = new CfFunction(name, type);
        func.isPrivate = isPrivate;
        func.isStatic = isStatic;
        func.formula = formula;
        this.functions.push(func);
        return func;
    };
    if (name === null || namespace === null) return '';
}

function CfModule(name, namespace) {
    this.javaVersion = cfb.Default.Module.javaVersion;
    this.name = name;
    this.namespace = namespace;
    this.classes = [];
    this.join = function(module, replaceNamespace) {
        var cls = new CfClass(null);
        var mod = new CfModule(null, null);
        mod = module;
        for (var c = 0; c < mod.classes.length; c++) {
            cls = mod.classes[c];
            if (replaceNamespace)
                cls.namespace = this.namespace;
            this.classes.push(cls);
        }   
    };
    this.addCls = function (name) {
        var cls = new CfClass(name);
        cls.namespace = this.namespace;
        this.classes.push(cls);
        return cls;
    };
    this.addInterface = function (name) {
        var cls = new CfClass(name);
        cls.namespace = this.namespace;
        cls.isInterface = true;
        this.classes.push(cls);
        return cls;
    };    
    this.alterJavaTemplate = function (value) {
        if (value === null)
            cfb.alterSource(cfb.Templates.tp_java, cfb.Templates.tp_java);
        else
            cfb.alterSource(cfb.Templates.tp_java, value);
    };
    this.alterCsTemplate = function (value) {
        if (value === null)
            cfb.alterSource(cfb.Templates.tp_cs2010, cfb.Templates.tp_cs2010);
        else
            cfb.alterSource(cfb.Templates.tp_cs2010, value);
    };
    this.alterQtWindowsTemplate = function (value) {
        if (value === null)
            cfb.alterSource(cfb.Templates.tp_qtWindows, cfb.Templates.tp_qtWindows);
        else
            cfb.alterSource(cfb.Templates.tp_qtWindows, value);
    };
    this.alterQtAndroidTemplate = function (value) {
        if (value === null)
            cfb.alterSource(cfb.Templates.tp_qtAndroid, cfb.Templates.tp_qtAndroid);
        else
            cfb.alterSource(cfb.Templates.tp_qtAndroid, value);
    };
    this.generate = function (outDir, templatesDir, prjName, diagram) {
        // current javascript engine is not stable for this function
        // for array.push(v), when v is a CfClass, CfFunction ... object, memory leaks
        // change to QScript or V8 may slove this problem
        cfb.setSource(templatesDir);
        var modHash = cfb.addModule(this.name);
        var cls = new CfClass(null);
        var prop = new CfProperty(null, null);
        var func = new CfFunction(null, cfb.Types.vt_unknown);
        var arg = new CfArgument(null, null);
        for (var c = 0; c < this.classes.length; c++) {
            cls = this.classes[c];
            var clsHash = cfb.addClass(modHash, cls.name, cls.serializable, cls.widgetVisible, this.namespace);
            for (var p = 0; p < cls.properties.length; p++) {
                prop = cls.properties[p];
                var propHash  = cfb.addProperty(clsHash, prop.name, prop.type, prop.usage, prop.readOnly, prop.constructable, prop.isStatic, prop.label, prop.hasRange);
            }
            for (var f = 0; f < cls.functions.length; f++) {
                func = cls.functions[f];
                var argsHash = 0;
                if (func.arguments.length > 0) {
                    argsHash = cfb.addArguments();
                    for (var a = 0; a < func.arguments.length; a++) {
                        arg = func.arguments[a];
                        var argHash = cfb.addArgument(argsHash, arg.name, arg.type, arg.usage);
                    }
                }
                var funcHash = cfb.addFunction(clsHash, func.name, func.usage, argsHash, func.returnClass !== null ? func.returnClass : func.returnType, func.isPrivate, func.isStatic, func.label, func.isForList);
            }
        }
        if (modHash > 0 && outDir !== null && prjName !== null) {
            if (diagram !== null)
                diagram();
            cfb.packModule(modHash, prjName, outDir);
            if (templatesDir === null)
                cfb.debug('resource project :: ', this.name + ' - ' + prjName);
            else
                cfb.debug('template project :: ', this.name + ' - ' + prjName);
        }

        cfb.releaseModule(modHash);
    };
}
//</core frame constructor>
