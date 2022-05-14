package leetcode;

import java.util.HashMap;

class Solution {
    // 面试题 01.05. 一次编辑
    public boolean oneEditAway(String first, String second) {
        int lenf = first.length();
        int lens = second.length();
        if (first.equals(second)) {
            return true;
        }
        if (Math.abs(lenf - lens) >= 2) {
            return false;
        }
        int fl = 0;
        int fr = lenf - 1;
        int sl = 0;
        int sr = lens - 1;
        while (fl < lenf && sl < lens && first.charAt(fl) == second.charAt(sl)) {
            fl++;
            sl++;
        }
        if (fl == fr + 1 && sl == sr + 1) {
            return true;
        }
        while (fr >= 0 && sr >= 0 && first.charAt(fr) == second.charAt(sr)) {
            fr--;
            sr--;
        }
        // 改
        if (lenf == lens && fl == fr && sl == sr && fl == sl) {
            return true;
        }
        // 增删
        if (lenf < lens && fr == fl - 1 && sl == sr) {
            return true;
        }
        if (lenf > lens && fl == fr && sr == sl - 1) {
            return true;
        }
        return false;
    }
    // 691. 贴纸拼词
    private int[] toStrMap(String str){
        int[] result=new int[26];
        for (int i = 0; i < str.length(); i++) {
            result[str.charAt(i)-'a']++;
        }
        return result;
    }
    private int[] strMapMinus(int[] left, int[] right){
        int[] result=new int[26];
        for(int i=0;i<26;i++){
            result[i]=left[i]-right[i]>=0?left[i]-right[i]:0;
        }
        return result;
    }
    private boolean strMapHaveCommon(int[] left, int[] right){
        for(int i=0;i<26;i++){
            if(left[i]!=0 &&right[i]!=0){
                return true;
            }
        }
        return false;
    }
    private String strMapToSortedStr(int[] strMap){
        String result="";
        for (int i = 0; i < strMap.length; i++) {
            for(int j=0;j<strMap[i];j++){
                result+=(char)((int)i+'a');
            }
        }
        return result;
    }
    private int dp(int[] targetStrMap,int[][] stickersStrMap,HashMap<String,Integer> memo) {
        String sortedTargetStr=strMapToSortedStr(targetStrMap);
        if(memo.containsKey(sortedTargetStr)){
            return memo.get(sortedTargetStr);
        }
        int result=Integer.MAX_VALUE;
        for (int[] stickerStrMap : stickersStrMap) {
            if(strMapHaveCommon(targetStrMap, stickerStrMap)){
                int[] nextTargetStrMap=strMapMinus(targetStrMap, stickerStrMap);
                int current=dp(nextTargetStrMap, stickersStrMap, memo);
                if(current!=Integer.MAX_VALUE){
                    result=current+1<result?current+1:result;
                }
            }
        }
        memo.put(sortedTargetStr, result);
        return result;
    }
    public int minStickers(String[] stickers, String target) {
        int[] targetStrMap = toStrMap(target);
        int[][] stickersStrMap = new int[stickers.length][];
        for (int i = 0; i < stickers.length; i++) {
            stickersStrMap[i] = toStrMap(stickers[i]);
        }
        HashMap<String,Integer> memo=new HashMap<String,Integer>();
        memo.put("",0);
        int result=dp(targetStrMap, stickersStrMap, memo);
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
