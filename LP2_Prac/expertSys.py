
def rule1(sym):
    if 'fever' in sym and 'cough' in sym:
        return 'u may have flu'
    return 0

def rule2(sym):
    if 'swelling' in sym and 'pain' in sym:
        return 'u may have fracture'
    return 0

def rule3(sym):
    if 'breath problem' in sym and 'vomiting' in sym:
        return 'u may have cancer'
    return 0

def rule4(sym):
    if 'breath problem' in sym and 'chest problem' in sym:
        return 'u may have heart attack'
    return 0

def diagnosis(sym):
    results=[]
    rules=[rule1,rule2,rule3,rule4]
    for x in rules:
        result=x(sym)
        if(result):
            results.append(result)
    if len(results)==0:
        return 'we cant'
    if len(results)==1:
        return results[0]
    else:
        for y in results:
            print(y)
    

sym=['fever','cough','swelling','pain']
print(diagnosis(sym))