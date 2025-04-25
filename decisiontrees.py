import math

class DecisionTree:
    def __init__(self, criterion="gini"):
        self.criterion = criterion  # Criterion for split ('gini' or 'entropy')
        self.best_feat = None       # Best feature index for splitting
        self.best_thresh = None     # Best threshold for splitting

    # Function to calculate Gini Impurity
    def gini(self, y):
        class_counts = {}
        for label in y:
            class_counts[label] = class_counts.get(label, 0) + 1
        
        impurity = 1
        total_count = len(y)
        for count in class_counts.values():
            prob = count / total_count
            impurity -= prob ** 2
        return impurity

    # Function to calculate Entropy
    def entropy(self, y):
        class_counts = {}
        for label in y:
            class_counts[label] = class_counts.get(label, 0) + 1

        entropy_value = 0
        total_count = len(y)
        for count in class_counts.values():
            prob = count / total_count
            entropy_value -= prob * math.log2(prob)
        return entropy_value

    # Function to split the dataset based on feature and threshold
    def split(self, X, y, feature_index, threshold):
        left_idx = [i for i in range(len(X)) if X[i][feature_index] <= threshold]
        right_idx = [i for i in range(len(X)) if X[i][feature_index] > threshold]
        
        return (
            [X[i] for i in left_idx], [y[i] for i in left_idx],
            [X[i] for i in right_idx], [y[i] for i in right_idx]
        )

    # Function to find the best split based on Gini or Entropy
    def best_split(self, X, y):
        best_impurity = float('inf')  # Initialize best impurity to infinity
        best_feat = None              # Initialize best feature index as None
        best_thresh = None            # Initialize best threshold as None

        # Loop through each feature in the dataset
        for feature_index in range(len(X[0])):
            values = set([row[feature_index] for row in X])  # Get unique values for the current feature
            
            # Loop through each unique value of the feature
            for val in values:
                X_left, y_left, X_right, y_right = self.split(X, y, feature_index, val)  # Split the dataset based on the feature value
                
                # Skip if any of the splits is empty
                if len(y_left) == 0 or len(y_right) == 0:
                    continue
                
                # Calculate the weighted impurity (Gini or Entropy) for the split
                p_left = len(y_left) / len(y)
                p_right = len(y_right) / len(y)

                if self.criterion == "gini":
                    impurity_split = p_left * self.gini(y_left) + p_right * self.gini(y_right)
                elif self.criterion == "entropy":
                    impurity_split = p_left * self.entropy(y_left) + p_right * self.entropy(y_right)
                else:
                    raise ValueError("Invalid criterion! Use 'gini' or 'entropy'.")

                # If this split is better (lower impurity), update the best values
                if impurity_split < best_impurity:
                    best_impurity = impurity_split
                    best_feat = feature_index
                    best_thresh = val

        return best_feat, best_thresh  # Return the best feature and threshold


# Example Dataset
X = [[2, 3], [1, 1], [2, 4], [3, 4], [4, 3], [3, 2]]
y = [0, 1, 0, 1, 0, 1]  # Target Labels

# Create a decision tree using Gini impurity criterion
tree_gini = DecisionTree(criterion="gini")
best_feat_gini, best_thresh_gini = tree_gini.best_split(X, y)
print(f"Best Split based on Gini Impurity: Feature {best_feat_gini}, Threshold {best_thresh_gini}")

# Create a decision tree using Entropy criterion
tree_entropy = DecisionTree(criterion="entropy")
best_feat_entropy, best_thresh_entropy = tree_entropy.best_split(X, y)
print(f"Best Split based on Entropy: Feature {best_feat_entropy}, Threshold {best_thresh_entropy}")
