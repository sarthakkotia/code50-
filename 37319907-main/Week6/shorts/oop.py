class Student():
    def __init__(self, name, id):
        self.name = name
        self.id = id


    def changeID(self, name):
        self.id = id

    def print(self):
        print("{}  {}".format(self.name,self.id))



jane = Student("Jane",12)
jane.print()
jane.changeID(15)
jane.print()