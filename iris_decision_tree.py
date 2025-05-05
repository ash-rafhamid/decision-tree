
import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt

iris = load_iris()
X = iris.data
y = iris.target

iris_df = pd.DataFrame(data=X, columns=iris.feature_names)
iris_df['species'] = [iris.target_names[i] for i in y]

print("First 5 rows of the dataset:")
print(iris_df.head())

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = DecisionTreeClassifier(random_state=42)
model.fit(X_train, y_train)

predictions = model.predict(X_test)

accuracy = accuracy_score(y_test, predictions)
print(f"\nModel accuracy: {accuracy * 100:.2f}%")

feature_importance = model.feature_importances_
features = iris.feature_names

plt.figure(figsize=(10, 6))
plt.bar(features, feature_importance)
plt.title('Feature Importance for Iris Classification')
plt.xlabel('Features')
plt.ylabel('Importance')
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

print("\nTry your own prediction!")
print("Enter measurements in centimeters:")
sepal_length = float(input("Sepal length: "))
sepal_width = float(input("Sepal width: "))
petal_length = float(input("Petal length: "))
petal_width = float(input("Petal width: "))

new_flower = [[sepal_length, sepal_width, petal_length, petal_width]]
prediction = model.predict(new_flower)
print(f"This iris is predicted to be: {iris.target_names[prediction[0]]}")
