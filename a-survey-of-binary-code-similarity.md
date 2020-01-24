---
description: 'https://arxiv.org/pdf/1909.11424.pdf - Authors : Ifran Ul Haq, Juan Caballero'
---

# A Survey of Binary Code Similarity

[https://arxiv.org/pdf/1909.11424.pdf](https://arxiv.org/pdf/1909.11424.pdf) - Authors : Ifran Ul Haq, Juan Caballero

If I knew this paper from the beginning, my journey would be easier. But the struggling is worth it anyway, I have met a lot new friends and researchers that have the same interests.

About this blog post, I will try my best write just enough detail to convince readers to read the paper but still left a lot of joy for readers to explore themself. 

And, I know it's deficiency for not mentioning about "Graph-based Comparision" by Thomas Dullien and Rolf Rolles but I am keeping it for another post 😉 

### Binary Code Similarity

> Binary code similarity approaches compare two or more pieces of binary code to identify their similarities and differences

Understanding what people have done in the past is important because it's not just help you save your time but also expanding your knowledges about the research area, gaining information about the previous problems to know which problems are still left-over and to know if there is still room left for improvements on a working method. 

> Over the past 20 years numerous binary code similarity approaches have been proposed, but the research area has not yet been systematically analyzed.

To give the reader a big-picture view of Binary Code Similarity, author have done a great job of systematizing 61 approaches by 5 characteristics. It's also worth noting that there is not only 61 approaches through 20 years of researching, but these 61 approaches are quite distinctive to others. A deep explaination of these characteristics could be found in **VI** so I will not go any deeper, if you are curious, take a look at the original paper.

> For example, the approach systematization includes, among others,
>
> the number of input pieces of binary code being compared \(e.g., one-to-one, one-to-many, many-to-many\); 
>
> the granularity of the pieces of binary code analyzed \(e.g., basic blocks, functions, programs\); 
>
> whether the comparison happens at the syntactical representation, the graph structure, or the code semantics; 
>
> the type of analysis used \(e.g., static, dynamic, symbolic\), 
>
> and the techniques used for scalability \(e.g., hashing, embedding, indexing\).

They also differentiate these approaches by its application. For people who care more about applications, you can take a look at chapter **IV**, where author talks about different application of Binary Code Similarity with link to multiple approaches for  the corresponding application or just look at the below table. That would be great starting point for people who just get into the field or just care about one or few applications of Binary Code Similarity. 

![](.gitbook/assets/image%20%28266%29.png)

But due to my personal interests, I care more about the history of this research area. It's surprising to know that the need of Binary Code Similarity is actually came from the need of updating binary in low bandwith communication networks and the limited resources in some devices

> The increasing popularity of low bandwidth communication networks \(e.g., wireless\) and the limited resources in some devices, raised interest in techniques that would increase efficiency by transmitting a small patch that captured the differences between two versions of a binary, i.e., non-text, file, instead of transmitting the whole file

> In 1991, Reichenberger proposed a diffing technique for generating patches between arbitrary binary files without any knowledge about the file structure

Many others approaches have developed later on with the expansion of the scope from one-to-one to many-to-many and one-to-many.  But only until 2004,  the re-ordering problem was solved by Thomas Dullien with the introduction of the Small Primes Product \(SPP\) algorithm. SPP is a simple Local Sensitive Hashing algorithm but effective to solve re-ordering problem which was used in many tools these days. For example : [diaphora](https://github.com/joxeankoret/diaphora) and [KOKA algorithm](http://joxeankoret.com/blog/2018/11/04/new-cfg-based-heuristic-diaphora/) \(Koret-Karamitas\) which was used SPP to hash those features/characterestics that were extracted from AST tree.

Now, let take a deeper look at SPP and re-ordering problem.

![](.gitbook/assets/image%20%2824%29.png)

As you can see, those two mov instructions in two pictures which represent the same function were swapped. Though it doesn't change the functionality of the function but if you do hash the bytes of the function, the result will identify these are two different functions, which is wrong. Now it's time for SPP, a Local Sensitive Hashing algorithm, join the game.

> In computer science, **locality-sensitive hashing** \(**LSH**\) is an algorithmic technique that hashes similar input items into the same "buckets" with high probability.[\[1\]](https://en.wikipedia.org/wiki/Locality-sensitive_hashing#cite_note-MOMD-1) \(The number of buckets are much smaller than the universe of possible input items.\)[\[1\]](https://en.wikipedia.org/wiki/Locality-sensitive_hashing#cite_note-MOMD-1) Since similar items end up in the same buckets, this technique can be used for [data clustering](https://en.wikipedia.org/wiki/Cluster_analysis) and [nearest neighbor search](https://en.wikipedia.org/wiki/Nearest_neighbor_search). It differs from [conventional hashing techniques](https://en.wikipedia.org/wiki/Hash_function) in that **hash collisions are maximized, not minimized**

SPP is a simple algorithm which used the uniqeness of prime decompositions and the commutative of multiplication to solve the re-ordering problem

![](.gitbook/assets/image%20%2864%29.png)

Next, in last ten years from 2010 to 2019, we can see a huge change in scope and approaches in the fields due to the rapid growing of Internet Of Things and Machine Learning master race with some applications of some NLP methods to solve Binary Code Similarity problems

> The last decade \(2010-2019\) has seen a huge increase in the popularity of binary code similarity, with 52 approaches identified. The focus on this decade has been on binary code search approaches, with an emphasis since 2015 on its cross-architecture version \(16 approaches\), and in recent years on machine learning approaches.

Beside Static analysis and Dynamic Analysis, [Dataflow Analysis](https://www.geeksforgeeks.org/data-flow-analysis-compiler/) is also another common type of analysis which use methods like taint analysis and symbolic execution from Dynamic Analysis to track the data sources like registers,... 

> Dataflow analysis is a common type of analysis that examines how values propagate through the code.

These two methods can be used separately or combined like in **IBINHUNT**

> IBINHUNT uses both taint analysis and symbolic execution. It first uses taint analysis as a filter to find pieces of binary code that process the same user input, restricting the expensive subgraph isomorphism computation to those with the same taint label. And, it computes basic block similarity using symbolic formulas.

Another interesting thing is **Operand Normalization** 

> A normalization used by 17 approaches is to replace instruction operands with symbols that capture the operand type such as REG for register, MEM for memory, and IMM for immediate values. For example, add %eax,%ebx and add %ecx,%edx would be both represented as add ****REG,REG, matching the instructions despite different register allocations used by the compiler.

And **Operand Removal**

> A normalization used by nine approaches is to abstract an instruction only by its mnemonic or opcode, ignoring all operands. For example, add %eax, %ebx and add \[%ecx\], ****%edx would be both represented by add and considered similar, despite both using different operands.

So, instead of doing **Operand Removal** \(ex : mnemonic small primes product in [diaphora](https://github.com/joxeankoret/diaphora/)\), Can we do **Operand Normalization** which doesn't cost much more computing resources but can increase the reliability of the results?

Finally, I want to end this blog post with the note that author made when he was trying to compare these approaches. I think it's really hard to say which approach is better, so, what we can do when trying to do Binary Code Similarity is finding the righ tool for the job.

> Comparing accuracy across binary code similarity approaches is challenging for multiple reasons. First, only a small fraction of the proposed approaches have publicly released their code \(Section VII\). Since most approaches are not publicly available, comparison is often performed by re-implementing previous approaches, which may require significant effort. One advantage of reimplementation is that approaches can be compared on new datasets. The alternative to re-implementation is to evaluate the new approach on the same dataset used by a prior ap- proach, and compare with the reported results. This method is only used by 6 approaches \(GENIUS, BINGO, XMATCH, CACOMPARE, GEMINI, and BINARM\) likely because most datasets are custom and not publicly available. Fortunately, we observe that public code release has become more common in recent approaches. Second, the input comparison and input granularity may differ among approaches making it nearly impossible. For instance, it is hard to compare in a fair manner an approach that identifies program similarity using callgraphs \(e.g., SMIT\) with an approach comparing basic blocks \(e.g., INNEREYE\). Third, even when the input comparison and input granularity are the same, the evaluation metrics and methodology may differ, significantly impacting the measured accuracy.

