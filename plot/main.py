import matplotlib.pyplot as plt
import os

mesh = []
values = []

current_dir = os.path.dirname(__file__)
current_dir = os.path.dirname(current_dir)
file_path = os.path.join(current_dir, "../data", "data.txt")

print(file_path)

with open(file_path, "r") as file:
    for line in file:
        columns = line.split()
        if len(columns) == 2:
            mesh_value = float(columns[0])
            values_value = float(columns[1])

            mesh.append(mesh_value)
            values.append(values_value)

plt.plot(mesh, values)
plt.xlabel("x")
plt.ylabel("y")
plt.grid()

plt.savefig('plt.png')

