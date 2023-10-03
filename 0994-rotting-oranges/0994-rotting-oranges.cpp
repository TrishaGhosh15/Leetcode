class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> arr=grid;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(arr[row][col]==2)
                    q.push({{row,col},0});
            }
        }
        int anstime=0;
        while(!q.empty()){
            auto fNode=q.front();
            q.pop();

            int x=fNode.first.first;
            int y=fNode.first.second;
            int time=fNode.second;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0&&newX<arr.size()
                &&newY>=0 && newY<arr[0].size()
                &&arr[newX][newY]==1){
                    pair<int,int> newcor=make_pair(newX,newY);
                    q.push({newcor,time+1});

                    anstime=max(anstime,time+1);
                    arr[newX][newY]=2;
                }
            }
        }
        for(int i =0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1)
                return -1;
            }
        }
        return anstime;
    }
};