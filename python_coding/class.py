class student:
    def __init__(self,name,age,branch):
         self.name = name
         self.age = age
         self.branch = branch
    def showData(self):
        print(self.name," ",self.age, " " , self.branch )
    def __del__(self):
        print("Destructor called, student deleted.")

obj = student("John", 20, "Computer Science")
obj.showData()
obj2 = obj
# del obj
obj2.showData()  # This will raise an error since obj has been deleted

