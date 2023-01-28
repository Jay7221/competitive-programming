def main(towers: list):
    hg_towers = [t for t in towers if len(set(list(t))) == 1]
    dif_towers = [t for t in towers if len(set(list(t))) > 1]

    for _ in range(len(towers)):
        if not dif_towers:
            break
        mega_tower = dif_towers.pop(0)
        start, end = mega_tower[0], mega_tower[-1]
        for hg_tower in hg_towers[:]:
            if hg_tower.startswith(end):
                mega_tower += hg_tower
                hg_towers.remove(hg_tower)
            elif hg_tower.endswith(start):
                mega_tower = hg_tower + mega_tower
                hg_towers.remove(hg_tower)

        start, end = mega_tower[0], mega_tower[-1]

        for tower in dif_towers[:]:
            if tower.startswith(end):
                mega_tower += tower
                dif_towers.remove(tower)
            elif tower.endswith(start):
                mega_tower = tower + mega_tower
                dif_towers.remove(tower)

        dif_towers.append(mega_tower)

    mega_tower = ''.join(dif_towers) + ''.join(sorted(hg_towers, key=lambda el: el[0]))

    processed = set()
    prev_ch = mega_tower[0]
    for ch in mega_tower:
        if ch in processed:
            return 'IMPOSSIBLE'
        if ch != prev_ch:
            processed.add(prev_ch)
        prev_ch = ch

    return mega_tower


T = int(input())
for t in range(T):
    input()
    print(f"Case #{t + 1}: " + main(
        input().strip().split()
    ))


# AAAA AFC AA DA CCC GH