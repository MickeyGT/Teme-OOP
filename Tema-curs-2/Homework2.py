import sys
class derivate:
        givenfunct=""
        #initialization function that will prepare for the precompute function.
        def __init__(self,name):
            #expresie will hold the final derivate espression.
            self.expresie=""
            #givenfunct is the function that has been given to us in the input
            self.givenfunct=name
        def recognize(self,string):        
            if string[0:2]=='1/':
                    self.expresie=self.expresie+str(int(self.coef)*-1*int(string[6:len(string)-1]))+'/(X**'+str(int(string[6:len(string)-1])+1)+')'
            elif string=='X':
                self.expresie=self.expresie+str(int(self.coef)*1)
                return
            elif string[0:3]=='X**':
                self.coef=int(self.coef)*int(string[3:6])
                if self.coef!=1:
                    if int(string[3:6])-1!=1:
                        self.expresie=self.expresie+str(self.coef)+'*X**'+str(int(string[3:6])-1)
                    else:
                        self.expresie=self.expresie+str(self.coef)+'*X'
                else:
                     self.expresie=self.expresie+'X**'+str(int(string[3:6])-1)
        #this function gets us the coefficient and the function so we can derivate the function after
        def getCoefAndFunction(self,string):
             for i in range(0,len(string)):
                if string[i]=='*':
                    #if the coeficient is multiplied to the function, then the coeficient is the 
                    #first part of the string until * and the function is the part after the *
                    self.coef=string[0:i]
                    self.funct=string[i+1:len(string)]
                    return 
                elif string[i]=='/':
                    #if however we have / then the coeficient is the first part of the string until /
                    #but the function is going to be something like this '/(x+1)' so we have to add a 1.
                    self.coef=string[0:i]
                    self.funct="1"+string[i:len(string)]
                    return
             self.coef='1'
             self.funct=string
             return
 
        #this function will get us the current function and coefficient we're going to derivate.
        def getexp(self,string):
            for i in range(0,len(string)):
                if string[i]=='+' or string[i]=='-':
                    funct=string[0:i]
                    self.givenfunct=self.givenfunct[i:len(string)]
                    return funct
            self.givenfunct=""
            return string

        def precompute(self):
            #while we still have something that needs to be derivated
            while(self.givenfunct):
                #current will hold the function and coefficient that will be derivated.
                current = self.getexp(self.givenfunct)
                self.coef='1'
                self.getCoefAndFunction(current)
                self.recognize(self.funct)
                self.expresie=self.expresie + self.givenfunct[0:1]
                self.givenfunct=self.givenfunct[1:len(self.givenfunct)]
            for i in range(0,len(self.expresie)-1):
                if self.expresie[i:i+2]=='+-':
                    self.expresie=self.expresie[:i]+self.expresie[i+1:len(self.expresie)]
                elif self.expresie[i:i+2]=='-+':
                    self.expresie=self.expresie[:i+1]+self.expresie[i+2:len(self.expresie)]
            

def menu():
    print ('Menu of the problem:')
    print ('Option 1: Read the expression:.')
    print ('Option 2: Calculate and print the derivate equivalent.')
    print ('Option 3: Exit.')
    type = input('Please select an option: ')
    if type == '1':
        print('\n')
        deriv.precompute()
        menu()
    elif type == '2':
        print('\n')
        display()
        menu()
    elif type == '3': 
        print('Program will now close.')
        #not re-calling the menu the way we did with the 
        #other options so the program can now close.
    else:
        #menu for when an invalid option is picked.
        print('\n')
        print('Chosen option is invalid. Please pick again.\n')
        menu()
    print('\n')

#first call of the menu function. 
#It only needs to be called once because after 
#each operation the menu just gets called again.
expr='5*X**3+2*X**2+5/(X**2)'
deriv =derivate (expr)
print (deriv.expresie)
print (deriv.givenfunct)
deriv.precompute()
print (deriv.expresie)
menu()
