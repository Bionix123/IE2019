//Program de teste pentru comenzile vocale. Versiunea finala a fost refacuta in javascript.
def saveData():

    currentInputData["email"] = username.get()
    currentInputData["password"] = password.get()
    currentInputData["group_link"] = group_link_entry.get()
    currentInputData["scroll_count"] = scroll_count_entry.get()

    json_data = json.dumps(currentInputData)

    print(json_data)

    saveFile = open("settings.json","w")
    saveFile.write(json_data) 

def loadData():

    global group_link
    global scrollsCount

    with open('settings.json') as data:
        dataDict = json.loads(data.read())

    currentInputData = dataDict

    clearAll()

    username.insert(0, dataDict["email"])
    password.insert(0,dataDict["password"])
    group_link_entry.insert(0, dataDict["group_link"])
    scroll_count_entry.insert(0, dataDict["scroll_count"])

def clearAll():
    username.delete(0,END)
    password.delete(0,END)
    group_link_entry.delete(0,END)
    scroll_count_entry.delete(0,END)
