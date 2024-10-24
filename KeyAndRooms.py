class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        def dfs(rm):
            if rm in vis:
                return
            vis.add(rm)
            for key in rooms[rm]:
                dfs(key)
        vis = set()
        dfs(0)
        return len(vis) == len(rooms)
