# DSP-implementation_LMS_RNN

Implementation of the LMS and RNN code in Digital Signal Processor to see its realtime performance on input signals.

Continuation of our Active Noise Cancellation paper. The github repository of that paper is  https://github.com/Aakriti05/LMS-ANN-Project

The Digital Signal Processor (DSP) in question is Texas Instruments' TMS320C6713 DSP Starter Kit whose hardware specifications and documents can be found at http://www.ti.com/tool/TMDSDSK6713.

The `rnn.c` code is the C program implementation of our noise cancelling architecture. We are using weights that are trained on a more powerful workstation since the DSP is only going to be used for noise filtering and not training the network.
