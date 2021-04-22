package main

import (
	"bufio"
    "fmt"
    "os"
)

func main(){
	subject := [] string{"国語","数学","理科","社会","英語"}
	
	motimono := [] string{}

	subject_motimono := [][] string{
		{"国語の教科書","詩集暗唱ノート","国語のノート","漢字スキル","国語のワーク","国ワーク(答え)"},
		{"数学の教科書","数学のノート","数学のワーク","数学のワーク(答え)","計算反復練習ノート"},
		{"理科の教科書","理科のワーク","理科のワーク(答え)","理科のノート"},
		{"社会の教科書","地理のノート","歴史の教科書","社会のワーク"},
		{"英語の教科書","英語のワーク","英語のノート"},
	}
	for i := 0;i < len(subject);i++ {
		fmt.Println(subject[i] + "はありますか。   (y/n)")

		scanner := bufio.NewScanner(os.Stdin)
   		scanner.Scan()

		if scanner.Text() == "y" {
			sm := subject_motimono[i]
			for j := 0;j < len(sm);j++{
				motimono = append(motimono,sm[j])
			}
		}else if scanner.Text() == "n" {
				//nと打ったときの処理
			}else{
				fmt.Println("yかnで入力してください。")
				i -= 1
			}
		}

		fmt.Println("")
		fmt.Println("")
		fmt.Println("")

		fmt.Println("持ち物は")

		fmt.Println("筆箱")
		fmt.Println("下じき")
		
		fmt.Println("")
		for i := 0;i < len(motimono);i++ {
			fmt.Println(motimono[i])
		}
	}
