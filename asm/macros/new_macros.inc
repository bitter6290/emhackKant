@ return current (posType = 0) or map (posType = 1) position of object to VAR_0x8007 (x), VAR_0x8008 (y)
.macro getobjectxy localId:req, posType:req
setvar VAR_0x8000, \localId
setvar VAR_0x8001, \posType
special GetObjectPosition
.endm