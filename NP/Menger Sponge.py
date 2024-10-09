L, x_num, x_denom, y_num, y_denom, z_num, z_denom = map(int, input().split())

if L == 0:
    print(1)
    exit()

p_x, q_x = x_num, x_denom
p_y, q_y = y_num, y_denom
p_z, q_z = z_num, z_denom

for _ in range(L):
    d_x = (p_x * 3) // q_x
    p_x = (p_x * 3) % q_x

    d_y = (p_y * 3) // q_y
    p_y = (p_y * 3) % q_y

    d_z = (p_z * 3) // q_z
    p_z = (p_z * 3) % q_z

    count = (d_x == 1) + (d_y == 1) + (d_z == 1)
    if count == 2:
        print(0)
        exit()

print(1)
