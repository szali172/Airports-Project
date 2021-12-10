import pandas as pd

df = pd.read_csv('airports.csv')

print(df.shape)
    
airport_index = 1
    
for index in df.index:
    df.iloc[index, 0] = airport_index
    airport_index = airport_index + 1
    
df.to_csv('airports.csv', index=False)
        
    