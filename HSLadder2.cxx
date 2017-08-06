void HSLadder2( ){
	TRandom3 *rng = new TRandom3(1);
	TCanvas *c = new TCanvas();
	TH2D *h = new TH2D("", "", 50, .5, .6, 50, 0, 5000);
	Double_t winrates[50];
	Double_t winrate = .5;
	for(Int_t j=0;j<50;j++){
		Int_t trials = 1000;
		for(Int_t i=0;i<trials;i++){
			Int_t AcquiredStars = 0; //rank 20: 10, 15: 25
			Int_t NMatches = 0;
			Int_t Streak = 0;
			while(AcquiredStars < 96){
				Double_t match = rng->Uniform(0,1);
				NMatches++;
				if(match < winrate) {//win
					AcquiredStars++;
					Streak++;
					if(Streak>2 && AcquiredStars < 71) AcquiredStars++;
				}
				else{//loss
					if(AcquiredStars > 10) AcquiredStars--;
					Streak = 0;
				}
			}
			h->Fill(winrate,NMatches);
		}
		winrate+=.002;
	}
	h->Draw("colz");
	h->GetXaxis()->SetTitle("Winrate");
	h->GetYaxis()->SetTitle("Matches to legend");
}