import numpy as np

# Will make the first model here for Linear Regression
# By Bastien LEUWERS
# First in py then in cpp

class LinearRegression():
    '''
        EN: Ordinary Least Square with the algebraic direct solver using the pseudoinverse method
        FR(si pas à l'aise en anglais): Moindres carrés ordinaires avec le solveur direct algébrique utilisant la méthode pseudo-inverse
    '''
    
    def __init__(self):
        self.weights_ = np.array([])


    def fit(self, X, y):

        X = np.insert(X, 0, 1, axis=1) # add 1 to all element in the X array so that we can simplify the weights to not have an intercept
                
        # weights = ((X^T*X)^-1)*(X^T)*y
        self.weights_ = np.linalg.pinv(X.T.dot(X)).dot(X.T).dot(y)


    def predict(self, X):
        X = np.insert(X, 0, 1, axis=1)
        
        y_pred = [x.dot(self.weights_) for x in X]
        return y_pred


class LogisticRegression():    
    '''
        TODO: add description
    '''
    
    def __init__(self):
        pass

    def fit(self, X, y):
        pass

    def predict(self, X):
        pass



class MLPRegressor():
    '''
        TODO: add description
    '''
    
    def __init__(self):
        pass

    def fit(self, X, y):
        pass

    def predict(self, X):
        pass



class MLPClassifier():
    '''
        TODO: add description
    '''
    
    def __init__(self):
        pass

    def fit(self, X, y):
        pass

    def predict(self, X):
        pass
