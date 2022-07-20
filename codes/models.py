import numpy as np

# By Bastien LEUWERS
# Will make the first model here for Linear Regression


class LinearRegression():
    '''
        Ordinary Least Square with the algebraic direct solver using the pseudoinverse method.
        For classification, we only accept binary classification (0,1) and not multi-classes
    '''

    def __init__(self, is_classification=False):
        self.weights_ = np.array([])
        self.is_classification = is_classification


    def fit(self, X, y):

        X = np.insert(X, 0, 1, axis=1) # add 1 to all element in the X array so that we can simplify the weights to not have an intercept
        # weights = ((X^T*X)^-1)*(X^T)*y
        self.weights_ = np.linalg.pinv(X.T.dot(X)).dot(X.T).dot(y)

    
    def predict(self, X):
        X = np.insert(X, 0, 1, axis=1)
        
        y_pred = [x.dot(self.weights_) for x in X]

        # If the classification flag is on we round to the nearest number
        if self.is_classification:
            y_pred = np.rint(y_pred)
        return y_pred




class MLPClassifier():
    '''
        Multi-layer perceptrons model for classification, only Fully Connected Feedforward architecture available with stochastic gradient descent.
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