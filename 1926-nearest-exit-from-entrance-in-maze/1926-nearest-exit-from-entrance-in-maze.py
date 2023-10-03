class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        """
            . entrace cant be termed as exit cell
        """
        
        seen = set()
        exits = set()
        R, C = len(maze), len(maze[0])
        entrance = tuple(entrance)
        
        for r in range(R):
            if maze[r][0] == ".":
                exits.add((r, 0))
            if maze[r][C-1] == ".":
                exits.add((r, C-1))
        
        for c in range(C):
            if maze[0][c] == ".":
                exits.add((0, c))
            if maze[R-1][c] == ".":
                exits.add((R-1, c))
        
        if entrance in exits:
            exits.remove(entrance)
        
        
        
        q = [(entrance, 0)] # start, distance
        
        
        while q:
            curr_pos , d = q.pop(0)
            
            if curr_pos in exits:
                return d
            
            if curr_pos in seen:
                continue
            
            seen.add(curr_pos)
            
            
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx = dx + curr_pos[0]
                ny = dy + curr_pos[1]
                
                if 0 <= nx < R and 0 <= ny < C and maze[nx][ny] == ".":
                    q.append(((nx, ny), d + 1))
            
        
        return -1