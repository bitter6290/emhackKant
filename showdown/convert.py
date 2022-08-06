import os

if "convert.py" in os.listdir("."):
    os.chdir(os.path.abspath(os.path.join('..')))

stats = "src/data/pokemon/base_stats.h"
spreadFile = "src/data/trainer_spreads.h"
outFile = "src/data/trainer_showdown.h"

outReset = open(outFile, "w")
outReset.write("")
# Place a copy of your base_stats.h file in the same folder as run.py, along with your IV and EV spread, if they're in the same format as the sample file.

with open(spreadFile) as spreadGo:
    spreadsRaw = spreadGo.readlines()[28:]
with open(stats) as statsGo:
    abiFile = statsGo.readlines()
spreads = {}
spreadOffsets = []
cursor = 0
while spreadsRaw[cursor] != 'const u8 gIvSets[][6] = {\n':
    if spreadsRaw[cursor][0:2] == '\t[':
        spreadOffsets.append(cursor)
    cursor += 1
for i in spreadOffsets:
    spreads[spreadsRaw[i+11][11:len(spreadsRaw[i+11])-1]+
    str(int(spreadsRaw[i+4][2:len(spreadsRaw[i+4])-2])+253*int(spreadsRaw[i+5][2:len(spreadsRaw[i+5])-2])+
    253**2*int(spreadsRaw[i+6][2:len(spreadsRaw[i+6])-2])+253**3*int(spreadsRaw[i+7][2:len(spreadsRaw[i+7])-2])+
    253**4*int(spreadsRaw[i+8][2:len(spreadsRaw[i+8])-2])+253**5*int(spreadsRaw[i+9][2:len(spreadsRaw[i+9])-1]))] = spreadsRaw[i][2:len(spreadsRaw[i])-4]

cursor += 6
ivSpreads = {}
ivOffsets = []
while spreadsRaw[cursor] != '};':
    if spreadsRaw[cursor][0:2] == '\t[':
         ivOffsets.append(cursor)
    cursor += 1
for i in ivOffsets:
    ivSpreads[int(spreadsRaw[i+2][1:len(spreadsRaw[i+2])-2])+32*int(spreadsRaw[i+3][1:len(spreadsRaw[i+3])-2])+
              32**2*int(spreadsRaw[i+4][1:len(spreadsRaw[i+4])-2])+32**3*int(spreadsRaw[i+5][1:len(spreadsRaw[i+5])-2])+
              32**4*int(spreadsRaw[i+6][1:len(spreadsRaw[i+6])-2])+32**5*int(spreadsRaw[i+7][1:len(spreadsRaw[i+7])-1])] = spreadsRaw[i][2:len(spreadsRaw[i])-4]

ivSpreads[2**30-1] = "SPREAD_31_IV"
def evstoKey(evIn,natureIn):
    return str(natureIn)+str(evIn[0]+253*evIn[1]+253**2*evIn[2]+253**3*evIn[3]+253**4*evIn[4]+253**5*evIn[5])


def getAbilityNumber(speci,abi):
    for i in range(len(abiFile)):
        if abiFile[i].replace('\t','').replace(' ','') == "[SPECIES_"+speci+"]=\n":
            specOffset = i
            break
    for i in range(specOffset,specOffset+60):
        if abiFile[i].replace('\t','').replace(' ','')[0:11] == ".abilities=":
            abiSet = abiFile[i].replace('\t','').replace(' ','').replace('\n','').replace('},','')[12:].split(',')
            break
    return abiSet.index(abi)

overrides = {}

evOrder = ["HP","Atk","Def","Spe","SpA","SpD"]
numerals = ['0','1','2','3','4','5','6','7','8','9']

#  convertSets takes a path to a file as input, converts that file from Showdown to C format, and prints the result.
#  Make sure that each team has a name before it, formatted as ">>>NAME<<<".

def convertSets(path):
    with open(path) as f:
        lines = f.readlines()
    sets = []
    curSet = -1
    step = 0
    curEvs = [0,0,0,0,0,0]
    curIvs = [31,31,31,31,31,31]
    curNature = ""
    for i in lines:
        if(i[0:3] == "==="):
            curSet += 1
            curMon = -1
            j = 3
            while i[j] != ']':
                j += 1
            j += 2
            sets.append({"name":"sParty_"+i[j:len(i)-4].replace(' ',''),"party":[]})
            continue
        if i == '\n':
            step = 0
            if(curMon > -1):
                while(len(sets[curSet]["party"][curMon]["moves"]) < 4):
                    sets[curSet]["party"][curMon]["moves"].append("MOVE_NONE")
            continue
        if step == 0:
            curMon += 1
            sets[curSet]["party"].append({"name":"","item":"ITEM_NONE","ability":"","level":"100","spreadIv":"","spreadEv":"","moves":[],"hpType":None})
            nameEnd = 0
            while i[nameEnd] != ' ' or i[nameEnd-4:nameEnd] == 'Tapu':
                nameEnd += 1
            firstNameEnd = nameEnd
            sets[curSet]["party"][curMon]["name"] = "SPECIES_"+i[0:nameEnd].upper().replace('-','_').replace(' ','_')
            if(sets[curSet]["party"][curMon]["name"][len(sets[curSet]["party"][curMon]["name"])-5:] == "ALOLA"):
               sets[curSet]["party"][curMon]["name"] = sets[curSet]["party"][curMon]["name"] + 'N'
            elif(sets[curSet]["party"][curMon]["name"][len(sets[curSet]["party"][curMon]["name"])-5:] == "GALAR"):
               sets[curSet]["party"][curMon]["name"] = sets[curSet]["party"][curMon]["name"] + 'IAN'
            if i[firstNameEnd+1] not in ["@","("]:
                step += 1
                continue
            itemEnd = firstNameEnd+3
            if(i[itemEnd] == ')'):
                firstNameEnd += 4
            while i[itemEnd:itemEnd+2] != '\n':
                itemEnd += 1
            sets[curSet]["party"][curMon]["item"] = "ITEM_"+i[firstNameEnd+3:itemEnd-2].upper().replace(' ','_').replace('-','_')
            curEvs = [0,0,0,0,0,0]
            curIvs = [31,31,31,31,31,31]
            curNature = ""
            step += 1
            continue
        if step == 1:
            if i[0] != 'A':
                step += 1
            else:
                abilityEnd = 9
                while i[abilityEnd:abilityEnd+2] not in ['  ','\n']:
                    abilityEnd += 1
                currentAbility = "ABILITY_" + i[9:abilityEnd].upper().replace(' ','_')
                sets[curSet]["party"][curMon]["ability"] = currentAbility
                step += 1
                continue
        if step == 2:
            if(i[0] != 'L'):
                step += 1
            else:
                sets[curSet]["party"][curMon]["level"] = i[7:len(i)-1]
                while sets[curSet]["party"][curMon]["level"][len(sets[curSet]["party"][curMon]["level"])-1] == ' ':
                    sets[curSet]["party"][curMon]["level"] = sets[curSet]["party"][curMon]["level"][:len(sets[curSet]["party"][curMon]["level"])-1]
                step += 1
                continue
        if step == 3:
            if(i[0] != 'E'):
               sets[curSet]["party"][curMon]["spreadIv"] = "SPREAD_16_IV"
               sets[curSet]["party"][curMon]["spreadEv"] = "SPREAD_80_EV"
               step = 6
            else:
                cursor = 5
                while i[cursor-1:cursor+1] != '\n':
                    curEv = ""
                    while i[cursor] in numerals:
                        curEv = curEv + i[cursor]
                        cursor += 1
                    cursor += 1
                    curStat = ""
                    while i[cursor] != ' ':
                        curStat = curStat + i[cursor]
                        cursor += 1
                    curEvs[evOrder.index(curStat)] = int(curEv)
                    cursor += 3
                step += 1
                continue
        if step == 4:
            curNature = "NATURE_"+i[0:len(i)-10].upper()
            step += 1
            continue
        if step == 5:
            if i == 'IVs: 0 Atk  \n': sets[curSet]["party"][curMon]["spreadIv"] = "SPREAD_LOW_ATTACK"
            elif i == 'IVs: 0 Spe  \n': sets[curSet]["party"][curMon]["spreadIv"] = "SPREAD_SLOW"
            elif i == 'IVs: 0 Atk, 0 Spe  \n': sets[curSet]["party"][curMon]["spreadIv"] = "SPREAD_SLOW_LA"
            else: sets[curSet]["party"][curMon]["spreadIv"] = "SPREAD_31_IV" 
            if evstoKey(curEvs,curNature) in spreads.keys(): sets[curSet]["party"][curMon]["spreadEv"] = spreads[evstoKey(curEvs,curNature)]
            else: print("Need spread for EVs "+str(curEvs) + ", nature "+curNature)
            step += 1
            if i[0:3] == "IVs": continue
        if step == 6:
            if i[2:14] == "Hidden Power":
                sets[curSet]["party"][curMon]["moves"].append("MOVE_HIDDEN_POWER")
                sets[curSet]["party"][curMon]["hpType"] = i[16:len(i)-4]
                if sets[curSet]["party"][curMon]["spreadIv"] == "SPREAD_LOW_ATTACK":
                    sets[curSet]["party"][curMon]["spreadIv"] = "SPREAD_HP_" + sets[curSet]["party"][curMon]["hpType"].upper() + "_LA"
                else: sets[curSet]["party"][curMon]["spreadIv"] = "SPREAD_HP_" + sets[curSet]["party"][curMon]["hpType"].upper()
            else: sets[curSet]["party"][curMon]["moves"].append("MOVE_"+i[2:len(i)-3].upper().replace(' ','_').replace('-','_'))
    outSets = open(outFile, "a")
    for i in sets:
        outSets.write("static const struct TrainerMonItemCustomMoves " + i["name"] + "[] = {")
        for j in i["party"]:
            outSets.write("\n\t{\n\t.iv = 0,\n\t.lvl = "+j["level"]+",")
            outSets.write("\n\t.species = " + j["name"] + ',')
            outSets.write("\n\t.heldItem = " + j["item"] + ',')
            outSets.write("\n\t.ability = " + str(getAbilityNumber(j["name"][8:],j["ability"])) + ',')
            outSets.write("\n\t.spreadEv = " + j["spreadEv"] + ',')
            outSets.write("\n\t.spreadIv = " + j["spreadIv"] + ',')
            outSets.write("\n\t.moves = " + str(j["moves"]).replace('[','{').replace(']','}').replace('\'','') + ',')

            outSets.write("\n\t},")
        outSets.write("\n};\n")

for sdIn in os.listdir("showdown"):
    if sdIn.endswith('.sd'):
        convertSets("showdown/"+sdIn)
